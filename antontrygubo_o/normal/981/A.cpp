#include<bits/stdc++.h>
 
#define ll long long 

using namespace std;

bool palindrom (string s)
{
    bool check = true;
    int n = s.length();
    for (int i = 0; i<n; i++) if (s[i]!=s[n-1-i]) check = false;
    return check;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    int n = s.length();
    string s1 = s.substr(0, n-1);
    if (!palindrom(s)) {cout<<n; return 0;}
    if (!palindrom(s1)) {cout<<n-1; return 0;}
    cout<<0;
    
}