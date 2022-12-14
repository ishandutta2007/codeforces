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
const int mxN=200020;
const int mxM=1000010;
const int MOD=30013;
const ll INF=100000000000001;
vector <int> yaksu[mxN];
int N;
int A[mxN];
int cnt[mxN];
int S[mxN];
int dp[mxN];
int main()
{
    gibon
    for(int i=1;i<=200000;i++)
    {
        int j=2*i;
        while(j<=200000)
        {
            yaksu[j].push_back(i);
            j+=i;
        }
    }
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=0;i<N;i++)    cin >> A[i];
        sort(A, A+N);
        for(int i=0;i<=200000;i++)  cnt[i]=0;
        for(int i=0;i<N;i++)    cnt[A[i]]++;
        S[0]=0;
        for(int i=1;i<=200000;i++)    S[i]=S[i-1]+cnt[i];
        for(int i=0;i<=200000;i++)  dp[i]=-1;
        for(int i=1;i<=200000;i++)
        {
            dp[i]=S[i-1];
            if(cnt[i]==0)   continue;
            for(int nxt : yaksu[i])
            {
                if(cnt[nxt]==0) continue;
                dp[i]=min(dp[i], dp[nxt]+S[i-1]-S[nxt]);
            }
        }
        int ans=1000000;
        for(int i=1;i<=200000;i++)
        {
            if(cnt[i]==0)   continue;
            ans=min(ans, dp[i]+S[200000]-S[i]);
        }
        cout << ans << '\n';
    }
}