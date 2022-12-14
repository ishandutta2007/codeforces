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
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=1000020;
const int mxM=350;
const int mxK=105;
const int MOD=1000000007;
const ll INF=1000000000005;
int N, M;
int A[mxN], B[mxN];
vector <int> coor;
vector <pii> cont[2*mxN];
ll ans;
int seg[4*mxN], lazy[4*mxN];
int solv0(int pos)
{
    int ret=0;
    while(pos!=0)   ret+=seg[pos], pos-=pos&(-pos);
    return ret;
}
void upd0(int pos)
{
    while(pos<=coor.size())   seg[pos]++, pos+=pos&(-pos);
}
void init1(int idx, int s, int e)
{
    lazy[idx]=0;
    if(s==e)
    {
        seg[idx]=N-s;
        return;
    }
    int mid=(s+e)/2;
    init1(2*idx, s, mid);
    init1(2*idx+1, mid+1, e);
    seg[idx]=min(seg[2*idx], seg[2*idx+1]);
}
void propagate1(int idx)
{
    seg[2*idx]+=lazy[idx];  seg[2*idx+1]+=lazy[idx];
    lazy[2*idx]+=lazy[idx]; lazy[2*idx+1]+=lazy[idx];
    lazy[idx]=0;
}
void upd1(int idx, int s1, int e1, int s2, int e2, int val)
{
    if(s2>e1 || s1>e2)  return;
    if(s2<=s1 && e1<=e2)
    {
        seg[idx]+=val;
        lazy[idx]+=val;
        return;
    }
    propagate1(idx);
    int mid=(s1+e1)/2;
    upd1(2*idx, s1, mid, s2, e2, val);
    upd1(2*idx+1, mid+1, e1, s2, e2, val);
    seg[idx]=min(seg[2*idx], seg[2*idx+1]);
}
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        coor.clear();
        ans=0;
        for(int i=1;i<=N;i++)   cin >> A[i], coor.push_back(A[i]);
        for(int i=1;i<=M;i++)   cin >> B[i], coor.push_back(B[i]);
        sort(coor.begin(), coor.end());
        coor.erase(unique(coor.begin(), coor.end()), coor.end());
        for(int i=0;i<coor.size();i++)  cont[i].clear();
        for(int i=1;i<=N;i++)
        {
            A[i]=lower_bound(coor.begin(), coor.end(), A[i])-coor.begin();
            cont[A[i]].emplace_back(i, 1);
        }
        for(int i=1;i<=M;i++)
        {
            B[i]=lower_bound(coor.begin(), coor.end(), B[i])-coor.begin();
            cont[B[i]].emplace_back(i, 2);
        }
        for(int i=1;i<=coor.size();i++)    seg[i]=0;
        for(int i=1;i<=N;i++)
        {
            ans+=solv0(coor.size())-solv0(A[i]+1);
            upd0(A[i]+1);
        }
        init1(1, 0, N);
        for(int i=coor.size()-1;i>=0;i--)
        {
            for(pii ele : cont[i])  if(ele.sec==1)  upd1(1, 0, N, 0, ele.fir-1, -1);
            for(pii ele : cont[i])  if(ele.sec==2)  ans+=seg[1];
            for(pii ele : cont[i])  if(ele.sec==1)  upd1(1, 0, N, ele.fir, N, 1);
        }
        cout << ans << '\n';
    }

}