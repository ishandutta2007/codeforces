#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int n, k;
    cin>>n>>k;
    if(k>=1e5)
    {
    	cout<<"No";
    	return 0;
    }
    set<int> s;
    for(int i=1;i<=k;i++)
    {
    	s.insert(n%i);
    }
    if(s.size()==k)
    {
    	cout<<"Yes";
    }
    else
    {
    	cout<<"No";
    }
    return 0;
}