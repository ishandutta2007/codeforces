#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int a[N];

int32_t main()
{
    IOS;
    string s;
    cin>>s;
    n=s.size();
    for(int i=1;i<=n;i++)
    	a[i]=s[i-1]-'0';
    int ct1=0;
    for(int i=2;i<=n;i++)
    {
    	ct1+=(a[i]==1);
    }
    int ans=0, carry=0;
    for(int i=n;i>=1;i--)
    {
    	a[i]+=carry;
    	if(a[i]==1)
    	{
    		a[i]++;
    		ans++;
    	}
    	carry=a[i]/2;
    	ans++;
    }
    if(ct1==0)
    	ans-=2;
    cout<<ans;
    return 0;
}