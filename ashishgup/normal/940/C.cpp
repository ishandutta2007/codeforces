#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, k;
string s;
set<char> cur;

int32_t main()
{
    cin>>n>>k;
    cin>>s;
    for(auto it:s)
        cur.insert(it);
    char first=*(cur.begin());
    char last=*(--cur.end());
    if(k>n)
    {
        cout<<s;
        for(int i=1;i<=k-n;i++)
        {
            cout<<*(cur.begin());
        }
        return 0;
    }
    else
    {
        for(int i=k-1;i>=0;i--)
        {
            if(s[i]!=last)
            {
                s[i]=*(cur.upper_bound(s[i]));
                break;
            }
            else
            {
                s[i]=first;
            }
        }
        cout<<s.substr(0, k);
    }
    return 0;
}