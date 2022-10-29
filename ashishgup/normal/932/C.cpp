#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, a, b;
int ans[N];

int32_t main()
{
    IOS;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    	ans[i]=i;
   	if(a>b)
   		swap(a, b);
   	for(int i=0;i*b<=n;i++)
   	{
   		int bigcycle=i;
   		if((n-i*b)%a!=0)
   			continue;
   		if((n-i*b)<0)
   			continue;
   		int smallcycle=(n-i*b)/a;
   		int j;
   		for(j=1;bigcycle>0;j+=b, bigcycle--)
   		{
   			rotate(ans+j, ans+j+1, ans+j+b);
   		}
   		for(;smallcycle>0;j+=a, smallcycle--)
   		{
   			rotate(ans+j, ans+j+1, ans+j+a);
   		}
   		for(int i=1;i<=n;i++)
   			cout<<ans[i]<<" ";
   		return 0;
   	}
   	cout<<"-1";
    return 0;
}