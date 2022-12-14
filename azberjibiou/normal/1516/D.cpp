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
const int mxN=100100;
const int mxK=100000;
const ll MOD=1000000007;
const ll INF=100000000000001;
int N, Q;
int A[mxN];
vector <int> sosu[mxN];
bool sieve[mxN];
bool Chk[mxN];
int sps[mxN][20];
int main()
{
    gibon
    for(int i=2;i<=100000;i++)
    {
        if(sieve[i])    continue;
        for(int j=i;j<=100000;j+=i)
        {
            sosu[j].push_back(i);
            sieve[j]=true;
        }
    }
    cin >> N >> Q;
    for(int i=1;i<=N;i++)   cin >> A[i];
    int lc=1, rc=0;
    while(rc!=N)
    {
        int num=A[rc+1];
        bool jogun=true;
        for(int nxt : sosu[num])
        {
            if(Chk[nxt])
            {
                jogun=false;
                break;
            }
        }
        if(!jogun)
        {
            sps[lc][0]=rc;
            for(int nxt : sosu[A[lc]])  Chk[nxt]=false;
            lc++;
        }
        else
        {
            for(int nxt : sosu[num])    Chk[nxt]=true;
            rc++;
        }
    }
    for(int i=lc;i<=N;i++)  sps[i][0]=N;
    for(int i=1;i<=19;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(sps[j][i-1]==N)  sps[j][i]=N;
            else    sps[j][i]=sps[sps[j][i-1]+1][i-1];
        }
    }
    while(Q--)
    {
        int l, r;
        cin >> l >> r;
        int ans=0;
        for(int i=19;i>=0;i--)
        {
            if(sps[l][i]<r)
            {
                ans+=(1<<i);
                l=sps[l][i]+1;
            }
        }
        ans++;
        cout << ans << '\n';
    }
}