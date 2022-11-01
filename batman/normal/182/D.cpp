#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (5555)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

string s,t;
ll ans;

bool check(ll x)
{
	string ex="";
	if(((ll)t.size())%x!=0)
		return 0;
	for(int i=0;i<x;i++)ex+=s[i];
	for(int i=0;i<s.size();i+=x)
		for(int j=0;j<x;j++)
			if(s[i+j]!=s[j])
				return 0;
	for(int i=0;i<t.size();i+=x)
		for(int j=0;j<x;j++)
			if(t[i+j]!=s[j])
				return 0;
	return 1;			
}

int main()
{
	cin>>s>>t;
	for(int i=1;i<=s.size();i++)
		if(((ll)s.size())%i==0)
			ans+=check(i);
	cout<<ans;
    return 0;
}