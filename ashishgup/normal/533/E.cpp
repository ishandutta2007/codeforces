#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n;

int solve(string a, string b)
{
    int i=0, j=n-1;
    while(a[i]==b[i])
        i++;
    while(a[j]==b[j])
        j--;
    while(a[i+1]==b[i])
        i++;
    return i>=j;
}

int32_t main()
{
    IOS;
    string a, b;
    cin>>n>>a>>b;
    int ans=solve(a, b) + solve(b, a);
    cout<<ans;
    return 0;
}