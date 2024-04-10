#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;

int n;
int f[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>f[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
    	if(i==f[f[f[i]]])
    		ans=1;
    }
    if(ans)
    	cout<<"YES";
    else
    	cout<<"NO";
    return 0;
}