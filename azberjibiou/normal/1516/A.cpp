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
const int mxN=250010;
const int mxK=100000;
const ll MOD=1000000007;
const ll INF=100000000000001;
int N, K;
int A[mxN];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        for(int i=1;i<=N;i++)   cin >> A[i];
        for(int i=1;i<N;i++)
        {
            if(A[i]<=K)
            {
                A[N]+=A[i];
                K-=A[i];
                A[i]=0;
            }
            else
            {
                A[N]+=K;
                A[i]-=K;
                K=0;
                break;
            }
        }
        for(int i=1;i<=N;i++)   cout << A[i] << " ";
        cout << '\n';

    }
}