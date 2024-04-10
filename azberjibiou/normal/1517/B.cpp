#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define bp __builtin_popcount
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
const int mxN=106;
const int mxK=100000;
const ll MOD=1000000007;
const ll INF=100000000000001;
int N, M;
int B[mxN][mxN], ans[mxN][mxN];
bool Chk[mxN][mxN];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        for(int i=1;i<=N;i++)   for(int j=1;j<=M;j++)   cin >> B[i][j];
        for(int i=1;i<=N;i++)   for(int j=1;j<=M;j++)   Chk[i][j]=false;
        for(int i=1;i<=M;i++)
        {
            int mini=1000000001;
            pii pos;
            for(int j=1;j<=N;j++)
            {
                for(int k=1;k<=M;k++)
                {
                    if(Chk[j][k])   continue;
                    if(B[j][k]<mini)
                    {
                        pos.fir=j, pos.sec=k, mini=B[j][k];
                    }
                }
            }
            for(int j=1;j<=N;j++)
            {
                if(pos.fir==j)
                {
                    ans[j][i]=B[j][pos.sec];
                    Chk[j][pos.sec]=true;
                }
                else
                {
                    int maxi=-1, now;
                    for(int k=1;k<=M;k++)
                    {
                        if(Chk[j][k])   continue;
                        if(maxi<B[j][k])
                        {
                            maxi=B[j][k];
                            now=k;
                        }
                    }
                    ans[j][i]=maxi;
                    Chk[j][now]=true;
                }
            }
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=M;j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
    }
}