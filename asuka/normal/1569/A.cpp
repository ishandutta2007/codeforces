#include<bits/stdc++.h>
#define ll long long
#define N 114514
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
int t, pre[N];
char s[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		scanf("%s", s + 1);
		rep(i, 1, n) pre[i] = pre[i - 1] + (s[i] == 'a' ? 1 : -1);
		int al, ar;
		al = ar = -1;
		rep(l, 1, n) {
			rep(r, l, n) {
				if(pre[r] - pre[l - 1] == 0) al = l, ar = r;
			}
		}
		printf("%d %d\n", al, ar);
	}
	return 0;
}