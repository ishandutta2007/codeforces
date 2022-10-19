#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e3+7;
int F[LIM*LIM], ile[LIM*LIM], dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1}, n, m, k;
string T[LIM];
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
void uni(int a, int b) {
	if(fnd(a)==fnd(b)) return;
	ile[fnd(a)]+=ile[fnd(b)];
	F[fnd(b)]=fnd(a);
}
bool ok(int a, int b) {
	return 0<=a && a<n && 0<=b && b<m;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	rep(i, n*m) F[i]=i;
	rep(i, n) cin >> T[i];
	rep(i, n) rep(j, m) if(T[i][j]=='.') {
		rep(l, 4) if(ok(i+dx[l], j+dy[l])) {
			if(T[i+dx[l]][j+dy[l]]=='.') uni(i*m+j, (i+dx[l])*m+j+dy[l]);
			else ++ile[fnd(i*m+j)];
		}
	}
	while(k--) {
		int a, b;
		cin >> a >> b; --a; --b;
		cout << ile[fnd(a*m+b)] << '\n';
	}
}