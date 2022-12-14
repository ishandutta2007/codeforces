#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fir first
#define sec second
#define pdd pair<double, double>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pmax pair<__int128, __int128>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
int dx[4]= {0, 1, 0, -1}, dy[4]= {1, 0, -1, 0};
int ddx[8]={1, 1, 0, -1, -1, -1, 0, 1}, ddy[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int mxN=55;
const int mxM=350;
const int mxK=105;
const ll MOD=10000000000;
const ll INF=1000000000000000005;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        int N, M;
        cin >> N >> M;
        int mr=0, mw=0;
        for(int i=0;i<M;i++)
        {
            int a, b;
            cin >> a >> b;
            mr=max(mr, a);
            mw=max(mw, b);
        }
        if(mr+mw>N) cout << "IMPOSSIBLE\n";
        else
        {
            for(int i=0;i<mr;i++)   cout << "R";
            for(int i=0;i<mw;i++)   cout << "W";
            for(int i=0;i<N-mr-mw;i++)  cout << "R";
            cout << '\n';
        }
    }
}