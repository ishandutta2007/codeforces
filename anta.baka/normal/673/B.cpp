#include <bits/stdc++.h>
using namespace std;
const int N=100000;
vector<int> a(N,0),b(N,0);

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n,m;
    cin>>n>>m;
    for(int i=0,u,v; i<m; i++)
    {
        cin>>u>>v;
        u--; v--;
        if(u>v) swap(u,v);
        a[v]++; b[u]++;
    }

    for(int i=1; i<n; i++) a[i]+=a[i-1];
    for(int i=n-2; i>=0; i--) b[i]+=b[i+1];

    int ans=0;
    for(int i=1; i<n; i++)
        if(a[i-1]==0&&b[i]==0)
            ans++;

    cout<<ans;
    return 0;
}