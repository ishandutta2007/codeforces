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
const int mxN=5010;
const int mxM=22;
const int MOD=1000000007;
const ll INF=1000000000000000001;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        int N, K;
        cin >> N >> K;
        if(K<N)
        {
            if(N%K==0)  cout << 1 << '\n';
            else        cout << 2 << '\n';
            continue;
        }
        if(K%N==0)  cout << K/N << '\n';
        else    cout << K/N+1 << '\n';
    }
}