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
const int mxN=250010;
const int mxK=100000;
const ll MOD=1000000007;
const ll INF=100000000000001;
int N;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        ll N;
        cin >> N;
        if(N%2050!=0)
        {
            cout << -1 << '\n';
            continue;
        }
        N/=2050;
        int ans=0;
        while(N!=0)
        {
            ans+=N%10;
            N/=10;
        }
        cout << ans << '\n';
    }
}