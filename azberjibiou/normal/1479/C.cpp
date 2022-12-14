#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define fir first
#define sec second
#define pss pair<short, short>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<long double, long double>
typedef long long ll;
using namespace std;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1 , 0};
const int mxN=100005;
const int mxM=2000100;
const int mxK=32;
const ll MOD=1999;
const ll INF=100000000000001;
int N, M;
int pow2[27];
int A[22][22];
int main()
{
    gibon
    pow2[0]=1;
    for(int i=1;i<=26;i++)  pow2[i]=pow2[i-1]*2;
    cin >> N >> M;
    A[1][0]=1;
    for(int i=2;i<=20;i++)
    {
        int tmp=pow2[i-2];
        for(int j=i-1;j>=1;j--)
        {
            A[i][j]=tmp;
            tmp/=2;
        }
        A[i][0]=1;
    }
    if(N==1)
    {
        A[21][0]=1;
        N=2;
    }
    else
    {
        A[21][0]=-1;
    }
    for(int i=20;i>=1;i--)
    {
        if(M-N+1>=pow2[i-1])
        {
            A[21][i]=N-1;
            N+=pow2[i-1];
        }
        else
        {
            A[21][i]=-1;
        }
    }
    int cnt=0;
    for(int i=21;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(A[i][j]==-1) continue;
            cnt++;
        }
    }
    cout << "YES" << '\n';
    cout << "22 " << cnt << '\n';
    for(int i=21;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(A[i][j]==-1) continue;
            cout << 22-i << " " << 22-j << " " << A[i][j] << '\n';
        }
    }
}