#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N], b[N];
string s;

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        b[i]=s[i-1]-'0';
    }
    b[n]=0;
    set<int> cur;
    int l=1;
    for(int i=1;i<=n-1;i++)
    {
        cur.insert(a[i]);
        if(!b[i])
        {
            for(int j=l;j<=i;j++)
            {
                if(cur.find(j)==cur.end())
                {
                    cout<<"NO";
                    return 0;
                }
            }
            cur.clear();
            l=i+1;
        }
    }
    cout<<"YES";
    return 0;
}