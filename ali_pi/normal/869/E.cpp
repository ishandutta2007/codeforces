#include<bits/stdc++.h>

#define int long long

using namespace std;

int n,m,ans,f[3000][3000],q,x,y,xx,yy,c;

void putit(int x,int y,int z){
	for (int i=x;i<=n;i+=i&(-i))
		for (int j=y;j<=m;j+=j&(-j))f[i][j]+=z;
}int findit(int x,int y){
	ans=0;for (int i=x;i;i-=i&(-i))
		for (int j=y;j;j-=j&(-j))ans+=f[i][j];
	return ans;
}

signed main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;for (int i=1;i<=q;i++){
		cin>>c>>x>>y>>xx>>yy;if (c!=3){
			int k=(x<<15)^(y<<10)^(xx<<5)^yy;if (c==2)k=-k;
			putit(x,y,k);putit(xx+1,yy+1,k);
			putit(x,yy+1,-k);putit(xx+1,y,-k);
		}else{
			x=findit(x,y);y=findit(xx,yy);
			cout<<(x==y?"Yes":"No")<<endl;
		}
	}
}