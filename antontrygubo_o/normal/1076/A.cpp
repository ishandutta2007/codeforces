#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;



int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int idx = 0;
    while (idx<n-1&&s[idx]<=s[idx+1]) idx++;
    for (int i = 0; i<n; i++) if (i!=idx) cout<<s[i];
}