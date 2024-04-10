#include <bits/stdc++.h>
using namespace std;
string st;
long long n,ans,a[3000000];
int main()
{
    cin>>n;
    cin>>st;
    ans=100000000000;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<st.length();i++)
        if (st[i-1]=='R' && st[i]=='L') ans=min(ans,(a[i+1]-a[i])/2);
    if (ans==100000000000) ans=-1;
    cout<<ans;
}