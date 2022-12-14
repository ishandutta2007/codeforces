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
const int mxN=300010;
const int mxM=22;
const int MOD=1000000007;
const ll INF=1000000000000000001;
int N;
char S[mxN];
int R[mxN][2];  ///L, R
int L[mxN][2];  ///L, R
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        cin >> S;
        for(int i=0;i<=N;i++)   R[i][0]=R[i][1]=L[i][0]=L[i][1]=0;
        if(S[N-1]=='L') R[N-1][0]=1;
        else    R[N-1][1]=1;
        for(int i=N-2;i>=0;i--)
        {
            if(S[i]=='L')
            {
                R[i][0]=R[i+1][1]+1;
                R[i][1]=0;
            }
            else
            {
                R[i][0]=0;
                R[i][1]=R[i+1][0]+1;
            }
        }
        if(S[0]=='L')   L[1][0]=1;
        else    L[1][1]=1;
        for(int i=2;i<=N;i++)
        {
            if(S[i-1]=='L')
            {
                L[i][0]=L[i-1][1]+1;
                L[i][1]=0;
            }
            else
            {
                L[i][0]=0;
                L[i][1]=L[i-1][0]+1;
            }
        }
        cout << R[0][1]+1 << " ";
        for(int i=1;i<=N-1;i++) cout << R[i][1]+L[i][0]+1 << " ";
        cout << L[N][0]+1 << '\n';
    }
}