#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)100)
#define INF ((ll)2e9+100)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll a,b,c,d,n;
char ans[N][N];
vector <char> ex;

void solve(ll x,ll y,bool up)
{
	if(y==a+c)return ;
	ans[x][y]=ex.back();ex.pop_back();
	if(up)
	{
		if(x-1>=0)solve(x-1,y,1);
		else solve(0,y+1,0);
		return ;
	}
	if(y<a)
	{
		if(x!=b-1)solve(x+1,y,0);
		else solve(b-1,y+1,1);
		return ;
	}
	if(x!=d-1)solve(x+1,y,0);
	else solve(d-1,y+1,1);
}

int main()
{
	cin>>a>>b>>c>>d>>n;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		for(int j=0;j<x;j++)ex.push_back((char)(i+'a'));
	}
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)ans[i][j]='.';
	if(a%2)solve(b-1,0,1);
	else solve(0,0,0);
	cout<<"YES\n";
	for(int i=0;i<max(b,d);i++,puts(""))
		for(int j=0;j<a+c;j++)
			cout<<ans[i][j];
	return 0;
}