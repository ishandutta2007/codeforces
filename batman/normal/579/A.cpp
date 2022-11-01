#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N (201*1000)
ll n,ans;
int main()
{
    cin>>n;
    while(n)
    	ans+=(n%2),n/=2;
    cout<<ans;	
    return 0;
}