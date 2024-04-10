#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)

ll a,b,c,d;
char q[2];
string s;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(abs(c-d)>1)return cout<<-1,0;
	if(c==0 && d==0 && a && b)return cout<<-1,0;
	q[0]='4',q[1]='7';
	if(d>c || (d==c && a==d))swap(q[0],q[1]),swap(d,c),swap(a,b);
	for(int i=0;c>0 || d>0;i++)
	{
		if(i%2==0)
		{
			if(!a)return cout<<-1,0;
			s+=q[0];
			a--;
			if(i)d--;	
		}
		else
		{
			if(!b)return cout<<-1,0;
			s+=q[1];
			b--;
			c--;
		}
	}
	if(q[0]=='7')swap(a,b);
	string ans="";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='4')
			while(a)ans+='4',a--;
		ans+=s[i];
	}
	if(!b)return cout<<ans,0;
	string ans2="";
	for(int i=(ll)ans.size()-1;i>=0;i--)
	{
		if(ans[i]=='7')
		{
			for(int j=0;j<=i;j++)ans2+=ans[j];
			while(b)ans2+='7',b--;
			for(int j=i+1;j<ans.size();j++)ans2+=ans[j];
			return cout<<ans2,0;
		}
	}
    return 0;
}