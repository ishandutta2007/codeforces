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
const int mxN=5010;
const int mxM=22;
const int MOD=1000000007;
const ll INF=1000000000000000001;
int N, K;
ll A[mxN];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        for(int i=1;i<=N;i++)    cin >> A[i];
        A[0]=A[1];
        for(int i=2;i<=N;i++)
        {
            ll sum=0, lim=0;
            for(int j=1;j<i;j++)    sum+=A[j];
            if((A[i]*100)%K==0) lim=A[i]*100/K;
            else    lim=A[i]*100/K+1;
            if(lim<=sum)    continue;
            A[1]+=lim-sum;
        }
        cout << A[1]-A[0] << '\n';
    }
}