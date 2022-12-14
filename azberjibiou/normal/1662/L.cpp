#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pdd pair<double, double>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pmax pair<__int128, __int128>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]= {0, 1, 0, -1}, dy[4]= {1, 0, -1, 0};
int ddx[8]={1, 1, 0, -1, -1, -1, 0, 1}, ddy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int mxN=200025;
const int mxM=350;
const int mxK=105;
const ll MOD=10000000000;
const ll INF=1000000000000000005;
typedef struct pnt{
    ll x, y;
    int idx;
}pnt;
int N, V;
pnt A[mxN];
vector <ll> coorx, coory;
ll dp[mxN];
vector <pnt> cont[mxN];
int seg[4*mxN];
void upd(int idx, int s1, int e1, int pos, int val)
{
    if(s1==e1)  seg[idx]=max(seg[idx], val);
    else
    {
        int mid=(s1+e1)/2;
        if(pos<=mid)    upd(2*idx, s1, mid, pos, val);
        else    upd(2*idx+1, mid+1, e1, pos, val);
        seg[idx]=max(seg[2*idx], seg[2*idx+1]);
    }
}
int solv(int idx, int s1, int e1, int s2, int e2)
{
    if(s1>e2 || s2>e1)  return 0;
    if(s2<=s1 && e1<=e2)    return seg[idx];
    int mid=(s1+e1)/2;
    return max(solv(2*idx, s1, mid, s2, e2), solv(2*idx+1, mid+1, e1, s2, e2));
}
int main()
{
    gibon
    cin >> N >> V;
    for(int i=1;i<=N;i++)   cin >> A[i].y;
    for(int i=1;i<=N;i++)   cin >> A[i].x;
    for(int i=1;i<=N;i++)   A[i].idx=i;
    for(int i=1;i<=N;i++)
    {
        pll tmp={A[i].x, A[i].y};
        A[i].x=V*tmp.sec-tmp.fir;
        A[i].y=V*tmp.sec+tmp.fir;
    }
    for(int i=0;i<=N;i++)   coorx.push_back(A[i].x);
    for(int i=0;i<=N;i++)   coory.push_back(A[i].y);
    sort(coorx.begin(), coorx.end());   sort(coory.begin(), coory.end());
    coorx.erase(unique(coorx.begin(), coorx.end()), coorx.end());
    coory.erase(unique(coory.begin(), coory.end()), coory.end());
    for(int i=0;i<=N;i++)   A[i].x=lower_bound(coorx.begin(), coorx.end(), A[i].x)-coorx.begin();
    for(int i=0;i<=N;i++)   A[i].y=lower_bound(coory.begin(), coory.end(), A[i].y)-coory.begin();
    sort(A, A+N+1, [](pnt a, pnt b){return (a.x==b.x ? a.y>b.y : a.x>b.x);});
    for(int i=0;i<=N;i++)
    {
        dp[A[i].idx]=solv(1, 0, N, A[i].y, N)+1;
        upd(1, 0, N, A[i].y, dp[A[i].idx]);
    }
    cout << dp[0]-1;

}