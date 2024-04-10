#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, x;

int32_t main()
{
    IOS;
    cin>>n>>x;
    if(n==1)
    {
    	cout<<"YES"<<endl;
    	cout<<x;
    	return 0;
    }
    if(n==2 && x==0)
    {
    	cout<<"NO";
    	return 0;
    }
    else if(n==2)
    {
    	cout<<"YES"<<endl;
    	cout<<0<<" "<<x;
    	return 0;
    }
    cout<<"YES"<<endl;
    int curxor=0;
    for(int i=1;i<=n-3;i++)
    {
    	cout<<i<<" ";
    	curxor^=i;
    }
    int store=1LL<<17;
    if(curxor==x)
    {
    	cout<<store<<" "<<store*2<<" "<<(store ^ (store*2));
    }
    else
    {
    	cout<<0<<" "<<store<<" "<<(store ^ curxor ^ x)<<endl;
    }
    return 0;
}