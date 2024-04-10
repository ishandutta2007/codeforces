#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N];

int32_t main()
{
    IOS;
    int n, k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
   	{
   		cin>>a[i];
   	}
   	int max1=0, ans1=1, ans2=0;
   	for(int i=1;i<=k;i++)
   	{
   		int cur=n - (n%a[i]);
   		if(cur>max1)
   		{
   			max1=cur;
   			ans1=i;
   			ans2=n/a[i];
   		}
   	}
   	cout<<ans1<<" "<<ans2;
    return 0;
}