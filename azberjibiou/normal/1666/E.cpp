#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pdd pair<long double, long double>
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
const int mxN=100020;
const int MOD=998244353;
const ll INF=1e18;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
int ddx[8]={1, 1, 0, -1, -1, -1, 0, 1}, ddy[8]={0, -1, -1, -1, 0, 1, 1, 1};
ll L, N;
ll A[mxN];
ll tmp[mxN], tmax[mxN];
pll dp[mxN];
ll maxi;
ll ans[mxN];
bool ok1(ll k)
{
    for(int i=1;i<=N;i++)   tmp[i]=A[i]-k*i;
    tmax[N]=tmp[N];
    for(int i=N-1;i>=1;i--) tmax[i]=max(tmax[i+1], tmp[i]);
    for(int i=1;i<N;i++)    if(tmax[i+1]-tmp[i]>k)    return false;
    return true;
}
bool ok2(ll mini)
{
    dp[0]=pii(0, 0);
    for(int i=1;i<=N;i++)
    {
        dp[i].sec=dp[i-1].sec+maxi, dp[i].fir=dp[i-1].fir+mini;
        if(i==N)
        {
            if(dp[i].sec<L || dp[i].fir>L)  return false;
            return true;
        }
        dp[i].fir=max(dp[i].fir, A[i]);
        dp[i].sec=min(dp[i].sec, A[i+1]);
        if(dp[i].fir>dp[i].sec) return false;
    }
}
void make_ans(ll low, ll high)
{
    dp[0]=pii(0, 0);
    for(int i=1;i<=N;i++)
    {
        dp[i].sec=dp[i-1].sec+high, dp[i].fir=dp[i-1].fir+low;
        if(i!=N)
        {
            dp[i].fir=max(dp[i].fir, A[i]);
            dp[i].sec=min(dp[i].sec, A[i+1]);
        }
    }
    ans[N]=L;
    for(int i=N-1;i>=1;i--)
    {
        ans[i]=max(dp[i].fir, ans[i+1]-high);
    }
    for(int i=1;i<=N;i++)   cout << ans[i-1] << " " << ans[i] << '\n';
}
int main()
{
    gibon
    cin >> L >> N;
    for(int i=1;i<=N;i++)   cin >> A[i];
    A[N+1]=L;
    for(int i=1;i<=N;i++)
    {
        if(A[i]%i==0)   maxi=max(maxi, A[i]/i);
        else    maxi=max(maxi, A[i]/i+1);
        if((L-A[i])%(N+1-i)==0)   maxi=max(maxi, (L-A[i])/(N+1-i));
        else    maxi=max(maxi, (L-A[i])/(N+1-i)+1);
    }
    ll s1=0, e1=L;
    while(s1!=e1)
    {
        ll mid=(s1+e1)/2;
        if(ok1(mid))    e1=mid;
        else    s1=mid+1;
    }
    maxi=max(maxi, e1);

    if(ok2(maxi))
    {
        make_ans(maxi, maxi);
        return 0;
    }
    ll s2=1 , e2=maxi;
    while(s2!=e2)
    {
        ll mid=(s2+e2)/2;
        if(ok2(mid))    s2=mid+1;
        else    e2=mid;
    }
    make_ans(e2-1, maxi);
}