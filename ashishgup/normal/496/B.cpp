#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
string s;

int32_t main()
{
    IOS;
    cin>>n>>s;
    string ans=s;
    for(int j=0;j<=9;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]=='9')
                s[i]='0';
            else
                s[i]++;
        }
        for(int i=0;i<n;i++)
        {
            rotate(s.begin(), s.begin()+1, s.end());
            ans=min(ans, s);
        }
    }    
    cout<<ans;
    return 0;
}