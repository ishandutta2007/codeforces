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
const int mxN=100010;
const int mxM=22;
const int MOD=1000000007;
const ll INF=1000000000000000001;
int N, K;
ll A[mxN], B[mxN], C[mxN];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=1;i<=N;i++)   cin >> C[i];
        for(int i=1;i<=N;i++)   cin >> A[i];
        for(int i=1;i<=N;i++)   cin >> B[i];
        ll res=0, now=abs(A[2]-B[2]);
        for(int i=2;i<N;i++)
        {
            res=max(res, now+2+C[i]-1);
            if(A[i+1]==B[i+1])
            {
                now+=2+C[i]-1;
                res=max(res, now);
                now=0;
                continue;
            }
            now+=2+min(A[i+1]-1, B[i+1]-1)+min(C[i]-A[i+1], C[i]-B[i+1]);
            now=max(now, abs(A[i+1]-B[i+1]));
            //printf("i=%d, now=%lld\n", i, now);
        }
        now+=2+C[N]-1;
        res=max(res, now);
        cout << res << '\n';
    }
}