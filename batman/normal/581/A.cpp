#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (301*1000)
ll a,b;
int main()
{
    cin>>a>>b;
    cout<<min(a,b)<<" ";
    ll ans=max(a,b)-min(a,b);
    cout<<ans/2;
    
    
	return 0;
}