#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int a[N], b[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	b[i]=a[i];
    }
    sort(b+1, b+n+1);
    int l=n, r=1;
    for(int i=1;i<=n;i++)
    {
    	if(a[i]!=b[i])
    	{
    		l=min(l, i);
    		r=i;
    	}
    }
    if(l>r)
    	r=l;
    reverse(a+l, a+r+1);
    for(int i=1;i<=n;i++)
    {
    	if(a[i]!=b[i])
    	{
    		cout<<"no";
    		return 0;
    	}
    }
    cout<<"yes"<<endl;
    cout<<l<<" "<<r;
    return 0;
}