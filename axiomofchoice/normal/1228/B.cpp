#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
ll n,m,ans=1,mod=1000000007,f=0;
int s[1010][1010];
int main(){
	ios_base::sync_with_stdio(false); //cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
	repeat(i,0,n+2)
	repeat(j,0,m+2)
		s[i][j]=0;
	repeat(i,0,n){
		int y;
		cin>>y;
		repeat(j,0,y)
			if(s[i][j]==2)f=-1;
			else s[i][j]=1;
		if(s[i][y]==1)f=-1;
		else s[i][y]=2;
	}
	repeat(j,0,m){
		int x;
		cin>>x;
		repeat(i,0,x)
			if(s[i][j]==2)f=-1;
			else s[i][j]=1;
		if(s[x][j]==1)f=-1;
		else s[x][j]=2;
	}
	//repeat(i,0,n)
	//repeat(j,0,m)
		//cout<<s[i][j],(j==m-1)?cout<<"\n":cout;
	if(f==0)
	repeat(i,0,n)
	repeat(j,0,m)
		if(s[i][j]==0)ans=(ans*2)%mod;
	if(f==0)
		cout<<ans<<endl;
	else cout<<0<<endl;
	return 0;
}