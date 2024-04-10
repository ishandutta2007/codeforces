#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;

vector<int> b;

int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    int n = s.length();
    bool rev = false;
    vector<bool> a(n);
    for (int i = n-1; i>=0; i--)
    {
        if (s[i]=='b'&&(!rev)) a[i] = 0;
        else if (s[i]=='a'&&rev) a[i] = 0;
        else {a[i] = 1; rev = 1-rev;}
    }
    for (int i = 0; i<n; i++) cout<<a[i]<<' ';

}