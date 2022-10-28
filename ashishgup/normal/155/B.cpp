#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

const int N=1e3+5;

int n;
pair<int, int> a[N];

int32_t main()
{
    IOS;
   	cin>>n;
   	for(int i=1;i<=n;i++)
   	{
   		cin>>a[i].second>>a[i].first;
   	}
   	sort(a+1, a+n+1);
   	reverse(a+1, a+n+1);
   	int ans=0, ct=1;
   	for(int i=1;i<=n;i++)
   	{
   		ct--;
   		if(ct<0)
   			break;
   		ct+=a[i].first;
   		ans+=a[i].second;
   	}
   	cout<<ans;
    return 0;
}