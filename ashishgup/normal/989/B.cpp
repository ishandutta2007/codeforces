#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, p;
string s;

int32_t main()
{
    IOS;
    cin>>n>>p>>s;
    bool check=1;
    for(int i=p;i<n;i++)
    {
        if(s[i-p]=='.' && s[i]!='.')
        {   
            int cur=s[i]-'0';
            cur^=1;
            s[i-p]=(char)(cur+'0');
            check=0;
        }
        else if(s[i]=='.' && s[i-p]!='.')
        {
            int cur=s[i-p]-'0';
            cur^=1;
            s[i]=(char)(cur+'0');
            check=0;
        }
        else if(s[i]=='.' && s[i-p]=='.')
        {
            s[i-p]='0';
            s[i]='1';
            check=0;
        }
        else
        {
            check&=(s[i]==s[i-p]);
        }
    }
    if(check)
    {
        cout<<"No";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='.')
            s[i]='0';
    }
    cout<<s;
    return 0;
}