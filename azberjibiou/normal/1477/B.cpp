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
const int mxN=200010;
const int mxM=22;
const int MOD=1000000007;
const ll INF=1000000000000000001;
int N, K;
char S1[mxN], S2[mxN];
pii Q[mxN];
bool ans;
int seg[4*mxN], lazy[4*mxN];
void init(int idx, int s, int e)
{
    //printf("idx=%d, s=%d, e=%d\n", idx, s, e);
    lazy[idx]=-1;
    if(s==e)
    {
        seg[idx]=(S2[s]=='0' ? 1 : 0);
        return;
    }
    int mid=(s+e)/2;
    init(2*idx, s, mid);
    init(2*idx+1, mid+1, e);
    seg[idx]=seg[2*idx]+seg[2*idx+1];
}
void propa(int idx, int s, int e)
{
    if(lazy[idx]==-1)   return;
    if(lazy[idx]==1)
    {
        seg[2*idx]=0;
        seg[2*idx+1]=0;
        lazy[2*idx]=1;
        lazy[2*idx+1]=1;
        lazy[idx]=-1;
    }
    else
    {
        int mid=(s+e)/2;
        seg[2*idx]=mid-s+1;
        seg[2*idx+1]=e-mid;
        lazy[2*idx]=0;
        lazy[2*idx+1]=0;
        lazy[idx]=-1;
    }
}
int solv(int idx, int s, int e, int str, int fin)
{
    if(str>e || s>fin)  return 0;
    if(str<=s && e<=fin)    return seg[idx];
    propa(idx, s, e);
    int mid=(s+e)/2;
    return solv(2*idx, s, mid, str, fin)+solv(2*idx+1, mid+1, e, str, fin);
}
void upd(int idx, int s, int e, int str, int fin, int val)
{
    if(str>e || s>fin)  return;
    if(str<=s && e<=fin)
    {
        seg[idx]=(1-val)*(e-s+1);
        lazy[idx]=val;
        return;
    }
    propa(idx, s, e);
    int mid=(s+e)/2;
    upd(2*idx, s, mid, str, fin, val);
    upd(2*idx+1, mid+1, e, str, fin, val);
    seg[idx]=seg[2*idx]+seg[2*idx+1];
}
bool dfs(int idx, int s, int e)
{
    if(s==e)
    {
        if(seg[idx]==0 && S1[s]=='0')   return false;
        if(seg[idx]==1 && S1[s]=='1')   return false;
        return true;
    }
    propa(idx, s, e);
    int mid=(s+e)/2;
    if(!dfs(2*idx, s, mid)) return false;
    if(!dfs(2*idx+1, mid+1, e)) return false;
    return true;
}
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        cin >> S1+1;
        cin >> S2+1;
        for(int i=0;i<K;i++)    cin >> Q[i].fir >> Q[i].sec;
        init(1, 1, N);
        ans=true;
        for(int i=K-1;i>=0;i--)
        {
            //for(int j=1;j<=20;j++)  printf("seg[%d]=%d, %d\n", j, seg[j], lazy[j]);
            int res=solv(1, 1, N, Q[i].fir, Q[i].sec);
            //printf("i=%d, res=%d\n", i, res);
            if((Q[i].sec-Q[i].fir+1)%2==0 && res==(Q[i].sec-Q[i].fir+1)/2)
            {
                //printf("i=%d\n", i);
                ans=false;
                break;
            }
            if(2*res<Q[i].sec-Q[i].fir+1)
            {
                upd(1, 1, N, Q[i].fir, Q[i].sec, 1);
            }
            else
            {
                upd(1, 1, N, Q[i].fir, Q[i].sec, 0);
            }
        }
        if(!ans)
        {
            cout << "NO\n";
            continue;
        }
        if(dfs(1, 1, N))    cout << "YES\n";
        else    cout << "NO\n";
    }
}