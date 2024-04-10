#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gibon cin.tie(0); ios::sync_with_stdio(false);
int N, M;
vector <int> v[202020];
ll ans;
void input()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        v[i].push_back(0);
        for(int j=0;j<M;j++)
        {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
}
ll solv(int row)
{
    vector <int> vp;
    vp.resize(N+1);
    ll preans=2000000;
    for(int i=0;i<N;i++)
    {
        if(v[i][row]<=N*M && v[i][row]%M==row%M)
        {
            int chan=i+N-(v[i][row]-row)/M;
            chan%=N;
            vp[chan]++;
        }
    }
    for(int i=0;i<N;i++)
    {
        preans=min(preans, (ll)(N-vp[i]+i));
    }
    return preans;
}
int main()
{
    gibon
    input();
    for(int i=1;i<=M;i++)
    {
        ans+=solv(i);
    }
    cout << ans;
}