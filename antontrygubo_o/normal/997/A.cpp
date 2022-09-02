#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, a, b;
    cin>>n>>a>>b;
    ll counter = 0;
    bool t = false;
    string s;
    cin>>s;
    for (int i = 0; i<n; i++)
    {
        if (s[i]=='1') t = false;
        else if (s[i]=='0'&&t==false) {t = true; counter++;}
    }
    if (counter==0) cout<<0;
    else cout<<b+(counter-1)*min(a, b);
}