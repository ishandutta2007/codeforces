#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define bp __builtin_popcount
#define fir first
#define sec second
#define pss pair<short, short>
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=300010;
const int mxM=350;
const int mxK=350;
const ll MOD=998244353;
const ll INF=100000000000001;
int N;
vector <int> v1[mxN], v2[mxN];
int in[mxN], out[mxN], idxd;
ll seg[4*mxN], lazy[4*mxN];
int cnt, ans;
void init(int idx, int s, int e)
{
    seg[idx]=0; lazy[idx]=0;
    if(s==e)    return;
    int mid=(s+e)/2;
    init(2*idx, s, mid);
    init(2*idx+1, mid+1, e);
}
void propa(int idx, int s1, int e1)
{
    int mid=(s1+e1)/2;
    seg[2*idx]+=(ll)(mid-s1+1)*lazy[idx];
    seg[2*idx+1]+=(ll)(e1-mid)*lazy[idx];
    lazy[2*idx]+=lazy[idx];
    lazy[2*idx+1]+=lazy[idx];
    lazy[idx]=0;
}
ll solv(int idx, int s1, int e1, int s2, int e2)
{
    if(s2>e1 || s1>e2)  return 0;
    if(s2<=s1 && e1<=e2)    return seg[idx];
    propa(idx, s1, e1);
    int mid=(s1+e1)/2;
    return solv(2*idx, s1, mid, s2, e2)+solv(2*idx+1, mid+1, e1, s2, e2);
}
void upd(int idx, int s1, int e1, int s2, int e2, ll val)
{
    if(s2>e1 || s1>e2)  return;
    if(s2<=s1 && e1<=e2)
    {
        seg[idx]+=(ll)(e1-s1+1)*val;
        lazy[idx]+=val;
        return;
    }
    int mid=(s1+e1)/2;
    propa(idx, s1, e1);
    upd(2*idx, s1, mid, s2, e2, val);
    upd(2*idx+1, mid+1, e1, s2, e2, val);
    seg[idx]=seg[2*idx]+seg[2*idx+1];
}
void dfs_ord(int now)
{
    in[now]=idxd;
    for(int nxt : v2[now])
    {
        dfs_ord(nxt);
    }
    out[now]=idxd++;
}
void dfs_1(int now)
{
    int plu=-1, minu=-1;
    if(solv(1, 1, N, in[now], out[now])==0)
    {
        plu=now;
    }
    else
    {
        int t1=solv(1, 1, N, in[now], in[now]);
        int t2=solv(1, 1, N, out[now], out[now]);
        if(t1==t2)
        {
            minu=t1;
            plu=now;
        }
    }
    if(plu!=-1)
    {
        cnt++;
        upd(1, 1, N, in[now], out[now], now);
    }
    if(minu!=-1)
    {
        cnt--;
        upd(1, 1, N, in[minu], out[minu], -minu);
    }
    ans=max(ans, cnt);
    for(int nxt : v1[now])
    {
        dfs_1(nxt);
    }
    if(plu!=-1)
    {
        cnt--;
        upd(1, 1, N, in[now], out[now], -now);
    }
    if(minu!=-1)
    {
        cnt++;
        upd(1, 1, N, in[minu], out[minu], minu);
    }
}
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=1;i<=N;i++)
        {
            v1[i].clear();
            v2[i].clear();
        }
        for(int i=2;i<=N;i++)
        {
            int a;  cin >> a;
            v1[a].push_back(i);
        }
        for(int i=2;i<=N;i++)
        {
            int a;  cin >> a;
            v2[a].push_back(i);
        }
        idxd=1;
        dfs_ord(1);
        init(1, 1, N);
        cnt=0, ans=0;
        dfs_1(1);
        cout << ans << '\n';
    }
}