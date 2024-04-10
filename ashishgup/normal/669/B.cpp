#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
char d[N];
int a[N], vis[N];

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>d[i];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int cur=1;
    while(cur<=n && cur>=1 && !vis[cur])
    {
        vis[cur]=1;
        cur=cur + a[cur] * (d[cur]=='>'?1:-1);
    }
    if(cur<1 || cur>n)
        cout<<"FINITE";
    else
        cout<<"INFINITE";
}