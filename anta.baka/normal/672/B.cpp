#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin>>n>>s;
    vector<int> c(26,0);
    int cbad=0;
    for(int i=0; i<n; i++) { if(c[s[i]-'a']<0) cbad++; c[s[i]-'a']--; }
    int cgood=0;
    for(int i=0; i<26; i++) cgood+=(c[i]==0);
    if(cbad>cgood) cout<<-1;
    else cout<<cbad;
    return 0;
}