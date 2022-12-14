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
const int mxN=200010;
const int mxM=22;
const int MOD=1000000007;
const ll INF=1000000000000000001;
int N;
ll K;
ll A[mxN];
ll gcd(ll a, ll b)
{
    if(a<b) return gcd(b, a);
    if(a%b==0)  return b;
    return gcd(b, a%b);
}
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        for(int i=0;i<N;i++)    cin >> A[i];
        sort(A, A+N);
        ll gcdd=A[1]-A[0];
        for(int i=2;i<N;i++)    gcdd=gcd(gcdd, A[i]-A[0]);
        if(abs(A[0]-K)%gcdd==0) cout << "YES\n";
        else    cout << "NO\n";
    }
}