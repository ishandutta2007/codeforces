#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define N 1005
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
int n,m,f[N][N][2][2][2];
char x[N],y[N];
void inc(int &x,int y){
	x += y; (x>=mod?x-=mod:0);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",x+1); scanf("%s",y+1);
	n = strlen(x+1); m = strlen(y+1);
	rep(i,0,n){
		rep(j,0,m){
			if(i>0) f[i][j][0][1][0]++;
			if(j>0) f[i][j][1][0][1]++;
			if(i>0) {
				rep(p,0,1) rep(q,0,1){
					inc(f[i][j][0][1][q],f[i-1][j][0][p][q]*(x[i]!=x[i-1]));
					inc(f[i][j][0][1][q],f[i-1][j][1][p][q]*(x[i]!=y[j]));
				}
			}
			if(j>0){
				rep(p,0,1) rep(q,0,1){
					inc(f[i][j][1][p][1],f[i][j-1][0][p][q]*(y[j]!=x[i]));
					inc(f[i][j][1][p][1],f[i][j-1][1][p][q]*(y[j]!=y[j-1]));
				}
			}
		}
	}
	int res = 0;
	rep(i,1,n) rep(j,1,m) rep(p,0,1) inc(res,f[i][j][p][1][1]);
	printf("%d\n",res);
	return 0;
}