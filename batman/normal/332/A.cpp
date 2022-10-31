#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
int n,ans;
string s;
int main()
{ 
    cin>>n>>s;
    for(int i=n;i<s.size();i+=n)
        if(s[i-1]==s[i-2] && s[i-2]==s[i-3])
        {
            ans++;
            s[i]=s[i-1];
        }
    cout<<ans;  
    return 0;
}