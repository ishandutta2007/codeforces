#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m;
int a[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
    	int x, y;
    	cin>>x>>y;
    	a[x-1]+=y-1;
    	a[x+1]+=a[x]-y;
    	a[x]=0;
    }
    for(int i=1;i<=n;i++)
    	cout<<a[i]<<endl;
	return 0;
}