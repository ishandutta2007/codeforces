#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<char> a(n);
    for (int i = 0; i<n; i++) a[i] = s[i];
    sort(a.begin(), a.end());
    for (int i = 0; i<n; i++) cout<<a[i];
}