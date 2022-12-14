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
const int mxN=250000;
const int mxM=1010;
const int mxK=2000000;
const int MOD=1000000007;
const ll INF=1e15;
const ll P1=1000000007;
const ll P2=1000000009;
int N;
int A[mxN];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=1;i<=N;i++)   cin >> A[i];
        int maxi=0, mini=0;
        for(int i=1;i<=N;i++)
        {
            if(mini==0 || A[i]<A[mini]) mini=i;
            if(maxi==0 || A[i]>A[maxi]) maxi=i;
        }
        cout << mini << " " << maxi << '\n';
    }
}