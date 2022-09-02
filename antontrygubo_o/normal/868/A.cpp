#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    int n;
    cin>>n;
    bool first, second;
    first = 0; second = 0;
    for (int i = 0; i<n; i++)
    {
        string temp;
        cin>>temp;
        if (temp==s) {first = 1; second = 1;}
        if (temp[0]==s[1]) second = 1;
        if (temp[1]==s[0]) first = 1;
    }
    if (first&&second) cout<<"YES";
    else cout<<"NO";
}