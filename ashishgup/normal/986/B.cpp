#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int a[N], vis[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int totlen=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
            continue;
        int cur=a[i];
        int len=0;
        while(!vis[cur])
        {
            len++;
            vis[cur]=1;
            cur=a[cur];
        }   
        totlen+=(len-1);
    }
    if(totlen%2 == n%2)
        cout<<"Petr";
    else
        cout<<"Um_nik";
    return 0;
}