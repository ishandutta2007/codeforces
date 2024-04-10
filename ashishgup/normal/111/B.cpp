#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int last[N];
vector<int> fact[N];

void generate()
{
    for(int i=1;i<N;i++)
    {
        for(int j=1;i*j<N;j++)
        {
            fact[i*j].push_back(i);
        }
    }
}

int32_t main()
{ 
    IOS;
    int n;
    cin>>n;
    generate();
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        int x, y;
        cin>>x>>y;
        for(auto it:fact[x])
        {
            if(i-last[it]>y)
                ans++;
        }
        cout<<ans<<endl;
        for(auto it:fact[x])
            last[it]=i;
    }
    return 0;
}