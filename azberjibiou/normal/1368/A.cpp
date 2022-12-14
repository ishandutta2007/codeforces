#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pii pair<int, int>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=110000;
const int mxM=1010;
const ll MOD=1000000007;
const ll INF=1000000000000;
int N;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        int a, b, c;
        int ans=0;
        cin >> a >> b >> c;
        if(a>b) swap(a, b);
        while(b<=c)
        {
            a+=b;
            swap(a, b);
            ans++;
        }
        cout << ans << '\n';
    }
}