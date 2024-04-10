// Zzz
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=(b%2)?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

string s,t,x;
ll a,b,c,num[3];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>t>>x;
	if(s=="scissors")a=0,num[0]++;
	if(s=="paper")a=1,num[1]++;
	if(s=="rock")a=2,num[2]++;
	if(t=="scissors")b=0,num[0]++;
	if(t=="paper")b=1,num[1]++;
	if(t=="rock")b=2,num[2]++;
	if(x=="scissors")c=0,num[0]++;
	if(x=="paper")c=1,num[1]++;
	if(x=="rock")c=2,num[2]++;
	if(num[0] && num[1] && num[2])return cout<<"?",0;
	if(num[0]==3 || num[1]==3 || num[2]==3)return cout<<"?",0;
	if(num[0]==0)
	{
		if(num[1]==2)return cout<<"?",0;
		if(a==1)return cout<<"F",0;
		if(b==1)return cout<<"M",0;
		if(c==1)return cout<<"S",0;
	}
	if(num[1]==0)
	{
		if(num[2]==2)return cout<<"?",0;
		if(a==2)return cout<<"F",0;
		if(b==2)return cout<<"M",0;
		if(c==2)return cout<<"S",0;
	}
	if(num[2]==0)
	{
		if(num[0]==2)return cout<<"?",0;
		if(a==0)return cout<<"F",0;
		if(b==0)return cout<<"M",0;
		if(c==0)return cout<<"S",0;
	}
	return 0;
}