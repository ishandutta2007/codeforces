#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, k;
string s;

int32_t main()
{
    IOS;
    cin>>n>>k;
    if(k>n || (k==1 && n>1))
    {
        cout<<"-1";
        return 0;
    }
    s="a";
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(s[i-1]!=(char)(j+'a'))
            {
                s+=(char)(j+'a');
                break;
            }
        }
    }
    for(int i=n-1;k>2;i--, k--)
    {
        s[i]=(k+'a'-1);
    }
    cout<<s;
    return 0;
}