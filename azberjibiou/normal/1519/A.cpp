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
        ll r, b, d;
        cin >> r >> b >> d;
        if(r*(d+1)<b || b*(d+1)<r)  cout << "NO" << '\n';
        else    cout << "YES" << '\n';
    }
}