#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define X first
#define Y second
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ET cout << "\n"
#define FILL(i,n) memset(i,n,sizeof i)
#define SZ(a) ((int)a.size())
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

int arr[100005];
int vis[100005];

int main()
{
    int n,x,ans=0;
    cin >> n;
    for(int i=0;i<n;++i)
        cin >> arr[i];
    for(int i=0;i<n;++i)
    {
        if(!vis[arr[i]])
            while(!vis[arr[i]])
                cin >> x,vis[x]=1;
        else
            ++ans;
    }
    cout << ans << "\n";
}