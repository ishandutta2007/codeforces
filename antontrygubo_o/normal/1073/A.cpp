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
    for (int i = 0; i<n-1; i++) if (s[i]!=s[i+1]) {cout<<"YES"<<endl<<s[i]<<s[i+1]; return 0;}
    cout<<"NO";
    
}