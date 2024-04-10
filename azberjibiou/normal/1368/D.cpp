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
const int mxN=210000;
const int mxM=1010;
const ll MOD=1000000007;
const ll INF=1000000000000;
int N;
ll A[mxN];
int B[30];
ll Po2[30];
ll ans;
int main()
{
    gibon
    cin >> N;
    for(int i=0;i<N;i++)    cin >> A[i];
    ll po2=1;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(A[j]%(2*po2)>=po2)   B[i]++;
        }
        Po2[i]=po2;
        po2*=2;
    }
    for(int i=0;i<N;i++)
    {
        ll num=0;
        for(int j=19;j>=0;j--)
        {
            if(B[j]!=0)
            {
                num+=Po2[j];
                B[j]--;
            }
        }
        ans+=num*num;
    }
    cout << ans;
}