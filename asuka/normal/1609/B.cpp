#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, q, ans = 0;
char s[N];
bool check(int i) {
	if(i < 1 || i + 2 > n) return 0;
	if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') return 1;
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	rep(i, 1, n - 2) {
		if(check(i)) ans++;
	}
	while(q--) {
		int pos;
		char c[5];
		scanf("%d%s", &pos, c);
		if(c[0] != s[pos]) {
			rep(i, pos - 2, pos) {
				if(check(i)) ans--;
			}
			s[pos] = c[0];
			rep(i, pos - 2, pos) {
				if(check(i)) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}