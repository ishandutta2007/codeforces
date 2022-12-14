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
const ll INF=1e18;
const ll P1=1000000007;
const ll P2=1000000009;
int N;
ll A[mxN];
ll t;
ll ans;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=0;i<N;i++)    cin >> A[i];
        sort(A, A+N);
        ll mini=0, maxi=0;
        mini=(N-2)*A[0];
        maxi=(N-2)*A[N-1];
        for(int i=0;i<N;i++)    mini+=A[i], maxi+=A[i];
        if(mini>0 || maxi<0)
        {
            cout << "INF" << '\n';
            continue;
        }
        t=-A[0];
        ans=-INF;
        pll line={0, 0};
        line.fir+=A[0]+A[N-1];
        line.sec+=A[0]*A[N-1];
        for(int i=1;i<N-1;i++)
        {
            line.fir+=A[i]+A[0];
            line.sec+=A[i]*A[0];
        }
        ans=max(ans, line.fir*(-A[0])+line.sec);
        ans=max(ans, line.fir*(-A[1])+line.sec);
        for(int i=1;i<N-1;i++)
        {
            line.fir-=A[0]+A[i];
            line.sec-=A[0]*A[i];
            line.fir+=A[N-1]+A[i];
            line.sec+=A[N-1]*A[i];
            ans=max(ans, line.fir*(-A[i])+line.sec);
            ans=max(ans, line.fir*(-A[i+1])+line.sec);
        }
        cout << ans << '\n';
    }
}