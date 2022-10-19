#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
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
int t, n, a[N], ori[N][2];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		memset(ori, 0, sizeof ori);
		rep(i, 1, n) ori[a[i]][i % 2] ++;
		sort(a + 1, a + n + 1);
		bool flag = 1;
		rep(i, 1, n) {
			ori[a[i]][i % 2] --;
			if(ori[a[i]][i % 2] < 0) {
				flag = 0;
				break;
			}
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}