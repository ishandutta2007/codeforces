#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

char ans[N];
int sieve[N];

int32_t main()
{
    IOS;
    string s;
    cin>>s;
    int n=s.size();
    fill(sieve+1, sieve+n+1, 1);
    int sz=0;
    for(int i=2;i<=n/2;i++)
    {
    	if(sieve[i])
    	{
    		for(int j=1;i*j<=n;j++)
    		{
    			if(sieve[i*j])
    				sz++;
    			sieve[i*j]=0;
    		}
    	}
    }
    map<char, int> m;
    for(auto it:s)
    	m[it]++;
    vector<pair<int, char> > v;
    for(auto it:m)
    	v.push_back({it.second, it.first});
    sort(v.begin(), v.end());
    if(v.back().first<sz)
    {
    	cout<<"NO";
    	return 0;
    }
    for(int i=2;i<=n;i++)
    {
    	if(!sieve[i])
    		ans[i]=v.back().second;
    }
    cout<<"YES"<<endl;
    int idx=0;
    for(int i=1;i<=n;i++)
    {
    	if(sieve[i])
    	{
    		ans[i]=v[idx].second;
    		v[idx].first--;
    		if(v[idx].first==0)
    			idx++;
    	}
    	cout<<ans[i];
    }
    return 0;
}