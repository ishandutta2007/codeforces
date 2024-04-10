#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int a[N];

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    set<int> s;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	s.insert(a[i]);
    }
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
    	if(a[i]==(*(s.begin())))
    	{
    		v.push_back(i);
    	}
    }
    set<int> ans;
    for(int i=1;i<v.size();i++)
    {
    	ans.insert(v[i]-v[i-1]);
    }
    cout<<*(ans.begin());
    return 0;
}