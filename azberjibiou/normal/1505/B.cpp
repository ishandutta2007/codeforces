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
const int mxN=201000;
const int mxM=10000100;
const ll mxK=2500;
const int MOD=998244353;
const ll INF=1000000000000000001;
int N;
int f(int n)
{
    int ans=0;
    while(n!=0)
    {
        ans+=n%10;
        n/=10;
    }
    if(ans<10)  return ans;
    return f(ans);
}
int main()
{
    gibon
    cin >> N;
    cout << f(N);
}