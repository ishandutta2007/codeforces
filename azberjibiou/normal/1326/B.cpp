#include<bits/stdc++.h>
#define gibon cin.tie(0); ios::sync_with_stdio(false);
#define fir first
#define sec second
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long int ll;
const ll MOD=1000000007;
const ll INF=10000000000007;
int N;
ll B[201010], A[201010];
int main()
{
    gibon
    cin >> N;
    for(int i=1;i<=N;i++)   cin >> B[i];
    ll X=0;
    for(int i=1;i<=N;i++)
    {
        A[i]=X+B[i];
        X=max(X, A[i]);
    }
    for(int i=1;i<=N;i++)   cout << A[i] << " ";
}