#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pdd pair<long double, long double>
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
const int mxN=1002;
const int mxM=300000;
const int mxQ=3000010;
const ll MOD=998244353;
const ll INF=1e18;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
int ddx[8]={1, 1, 0, -1, -1, -1, 0, 1}, ddy[8]={0, -1, -1, -1, 0, 1, 1, 1};
int N, K;
ll A[mxN], mx[mxN];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        for(int i=1;i<=N;i++)   cin >> A[i];
        for(int i=0;i<K;i++)    mx[i]=0;
        for(int i=1;i<=N;i++)   mx[i%K]=max(mx[i%K], A[i]);
        ll sum=0;
        for(int i=0;i<K;i++)    sum+=mx[i];
        cout << sum << '\n';
    }
}