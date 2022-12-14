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
const int mxN=301000;
const int mxM=2100000;
const ll MOD=1000000007;
const ll INF=1000000000000;
int N, K, Z;
int A[mxN];
int main()
{
    gibon
    int t;
    cin >> t;
    while(t--)
    {
        cin >> N >> K >> Z;
        for(int i=0;i<N;i++)    cin >> A[i];
        ll ans=0;
        for(int i=0;i<=Z;i++)
        {
            ll sum=A[0];
            if(i>K-i)   continue;
            ll maxi=0;
            for(int j=1;j<=K-2*i;j++)
            {
                sum+=A[j];
            }
            for(int j=0;j<=K-2*i;j++)
            {
                maxi=max(maxi, (ll)A[j]+A[j+1]);
            }
            sum+=maxi*i;
            ans=max(ans, sum);
        }
        cout << ans << '\n';
    }
}