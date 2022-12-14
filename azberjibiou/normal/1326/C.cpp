#include<bits/stdc++.h>
#define gibon cin.tie(0); ios::sync_with_stdio(false);
#define fir first
#define sec second
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long int ll;
const ll MOD=998244353;
const ll INF=10000000000007;
int N, K;
int A[201010];
bool Chk[201010];
ll ans=1;
ll ansp=0;
int main()
{
    gibon
    cin >> N >> K;
    for(int i=1;i<=N;i++)   cin >> A[i];
    for(int i=N-K+1;i<=N;i++)   ansp+=i;
    for(int i=1;i<=N;i++)
    {
        if(A[i]>=N-K+1) Chk[i]=true;
        else    Chk[i]=false;
    }
    int str=1;
    while(!Chk[str])    str++;
    ll cnt=1;
    for(int i=str+1;i<=N;i++)
    {
        if(!Chk[i]) cnt++;
        else
        {
            ans*=cnt;
            ans%=MOD;
            cnt=1;
        }
    }
    cout << ansp << " " << ans;
}