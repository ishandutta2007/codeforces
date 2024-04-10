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
const int mxN=250000;
const int mxM=1010;
const int mxK=2000000;
const int MOD=1000000007;
const ll INF=1e15;
const ll P1=1000000007;
const ll P2=1000000009;
int N, K;
int A[mxN];
bool ans;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        ll N;
        cin >> N;
        ll p2=1, N0=N;
        while(N0%2==0)
        {
            p2*=2;
            N0/=2;
        }
        if(N0==1)
        {
            cout << -1 << '\n';
            continue;
        }
        else
        {
            if(p2*2>=N0+1)  cout << N0 << '\n';
            else    cout << 2*p2 << '\n';
        }
    }
}