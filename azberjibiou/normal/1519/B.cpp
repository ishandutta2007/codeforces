#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define bp __builtin_popcount
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
const int mxN=104;
const int mxM=104;
const int mxK=1000000;
const ll MOD=1000000007;
const ll INF=100000000000001;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        int N, M, K;
        cin >> N >> M >> K;
        ll a1=0;
        for(int i=1;i<=N-1;i++) a1+=1;
        for(int i=1;i<=M-1;i++) a1+=N;
        if(K==a1)   cout << "YES" << '\n';
        else    cout << "NO" << '\n';
    }
}