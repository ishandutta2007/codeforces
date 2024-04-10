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
int N, K;
int main()
{
    gibon
    cin >> N;
    K=3*N+4;
    cout << K << '\n';
    for(int i=1;i<=N+2;i++) cout << i << " " << i << '\n';
    for(int i=1;i<=N+1;i++) cout << i << " " << i+1 << '\n';
    for(int i=1;i<=N+1;i++) cout << i+1 << " " << i << '\n';
}