#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
typedef long long ll; const int inf=~0u>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
const int N=501;
#define int ll
int rec[N][N]; //==-1[l,r]==0[l,r][l,r] 
int calc(int l,int r){ //dp 
	int &x=rec[l][r];
	if(x!=-1)return x;
	int t;
	repeat(i,l,r)
	if((t=calc(l,i))==calc(i+1,r) && t>0){ //
		return x=t+1;
	}
	return x=0;
}
int dis[N]; //0i
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	mst(rec,-1);
	int n=read();
	repeat(i,0,n)rec[i][i]=read();
	fill(dis,dis+n+1,inf); dis[0]=0;
	repeat(i,0,n)
	repeat(j,i,n)
	if(calc(i,j)>0){ //ij+1
		dis[j+1]=min(dis[j+1],dis[i]+1);
	}
	cout<<dis[n]<<endl;
	return 0;
}