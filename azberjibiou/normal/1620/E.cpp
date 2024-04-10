#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=500010;
const int mxM=1000010;
const int mxK=500000;
const ll MOD=1000000007;
const ll INF=8000000000000000001;
int Q;
int idx[2*mxN], ridx[mxN], nidx;
bool Chk[mxN];
int par[2*mxN];
vector <int> v;
int findpar(int a)
{
    return (par[a]==a ? a : par[a]=findpar(par[a]));
}
void onion(int a, int b)
{
    int p=findpar(a), q=findpar(b);
    par[p]=q;
}
int main()
{
    gibon
    for(int i=1;i<=mxK;i++) idx[i]=i, ridx[i]=i;
    for(int i=1;i<=2*mxK;i++)   par[i]=i;
    nidx=mxK+1;
    cin >> Q;
    while(Q--)
    {
        int typ;
        cin >> typ;
        if(typ==1)
        {
            int x;
            cin >> x;
            v.push_back(ridx[x]);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            if(x==y)    continue;
            onion(ridx[x], ridx[y]);
            ridx[x]=nidx;
            idx[nidx]=x;
            nidx++;
        }
    }
    for(int nxt : v)
    {
        cout << idx[findpar(nxt)] << " ";
    }
}