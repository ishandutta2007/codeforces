#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (201*1000)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

string s;
ll num[30];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)num[(s[i]-'a')]++;
	for(int i=25,j=0;i>=0;i--)
	{
		if(num[i]%2==1)
		{
			while(num[j]%2==0)j++;
			if(i==j)
				break;
			num[j]++,num[i]--;		
		}		
	}	
	bool mark=0;
	char ex;
	string ans="";
	for(int i=0;i<26;i++)
	{
		if(num[i]%2==1)
			mark=1,ex=(i+'a'),num[i]--;
		for(int j=0;j<num[i]/2;j++)
			ans+=(i+'a');		
	}
	cout<<ans;
	if(mark)
		cout<<ex;
	for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];		
    return 0;
}