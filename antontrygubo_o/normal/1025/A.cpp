#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = 998244353;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a(26, 0);
    for (int i = 0; i<n; i++) a[s[i]-'a']++;
    if (n==1) {cout<<"YES"; return 0;}
    for (int i = 0; i<26; i++) if (a[i]>=2) {cout<<"YES"; return 0;}
    cout<<"NO";
}