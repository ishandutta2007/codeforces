#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool kek = true;
    if (n==1) 
    {
        kek = (s[0]=='1');
    }
    for (int i = 0; i<n-1; i++)
    {
        if (s[i]=='1'&&s[i+1]=='1') kek = false;
    }
    if (s[0]=='0'&&s[1]=='0') kek = false;
    if (s[n-2]=='0'&&s[n-1]=='0') kek = false;
    for (int i = 0; i<n-2; i++)
    {
        if (s[i]=='0'&&s[i+1]=='0'&&s[i+2]=='0') kek = false;
    }
    if (kek) cout<<"YES";
    else cout<<"NO";
}