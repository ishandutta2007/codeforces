#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=1e5+7, INF=1e9+7;
int odl[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, LIM) odl[i]=INF;
	queue<int>q;
	q.push(n);
	odl[n]=0;
	while(!q.empty()) {
		int p=q.front(); q.pop();
		if(p-1>0 && odl[p-1]==INF) {
			odl[p-1]=odl[p]+1;
			q.push(p-1);
		}
		if(p*2<LIM && odl[2*p]==INF) {
			odl[p*2]=odl[p]+1;
			q.push(p*2);
		} 
	}
	cout << odl[m] << '\n';
}