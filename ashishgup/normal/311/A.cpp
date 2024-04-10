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
   	int maxk=n*(n-1)/2;
   	if(k>=maxk)
   	{
   		cout<<"no solution";
   		return 0;
   	}
   	for(int i=1;i<=n;i++)
   	{
   		cout<<"0 "<<i<<endl;
   	}
    return 0;
}