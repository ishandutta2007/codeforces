#include<bits/stdc++.h>
#define ll long long
#define N 205
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
#define all(x) x.begin(),x.end()
using namespace std;
int n,m,f[N][N],col[N];
void bi(int x){
	//cout << x << endl;
	rep(i,1,n){
		if(f[x][i] <= n){
			//cout << i << endl;
			if(col[i] == -1) col[i] = col[x]^1,bi(i);
			else{
				if(col[i] == col[x]) {puts("NO"); exit(0);}
			}
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&m);
 	memset(f,0x3f,sizeof f);
 	memset(col,-1,sizeof col);
 	rep(i,1,m){
 		int u,v,flag;
 		scanf("%d%d%d",&u,&v,&flag);
 		if(flag) f[u][v] = 1,f[v][u] = -1;  //a_u - a_v <= 1 && a_v - a_u <= -1
 		else f[u][v] = 1,f[v][u] = 1;
 	}
 	col[1] = 0;// cout << ~col[1] << endl;
 	bi(1);
 	rep(i,1,n) f[i][i] = 0;
 	rep(k,1,n) rep(i,1,n) rep(j,1,n) f[i][j] = min(f[i][j],f[i][k]+f[k][j]); 
 	rep(i,1,n) if(f[i][i] < 0) {puts("NO"); return 0;}
 	int ans = -inf,id; id = 1;
 	rep(i,1,n) rep(j,1,n){
 		if(abs(f[i][j]) > ans) ans = abs(f[i][j]),id = i;
 	}
 	printf("YES\n%d\n",ans);
 	rep(i,1,n) printf("%d ",f[id][i]+114514);
	return 0;
}