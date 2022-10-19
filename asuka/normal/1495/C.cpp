#include<bits/stdc++.h>
#define ll long long
#define N 505
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,m;
char s[N][N],ans[N][N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		rep(i,1,n) scanf("%s",s[i]+1);
		if(n == 1) {
			rep(i,1,m) ans[1][i] = 'X';
			rep(i,1,n){
				rep(j,1,m) putchar(ans[i][j]);
				printf("\n");
			}
			continue;
		}
		rep(i,1,n+3) rep(j,1,m+3) ans[i][j] = '.';
		rep(i,1,n) rep(j,1,m) ans[i][j] = s[i][j];
		for(int i = 2;i <= n;i += 3){
			rep(j,1,m) ans[i][j] = 'X';
			if(ans[i+1][2]=='X'||ans[i+2][2]=='X') ans[i+1][2] = ans[i+2][2] = 'X';
			else ans[i+1][1] = ans[i+2][1] = 'X';
		}
		if(n%3 == 1) rep(i,1,m) if(ans[n][i] == 'X'&&ans[n][i-1] != 'X') ans[n-1][i] = 'X';
		rep(i,1,n){
			rep(j,1,m) putchar(ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}