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
const int mxN=5020;
const int mxM=104;
const int mxK=1000000;
const ll MOD=1000000007;
const ll INF=100000000000001;
int N, X;
int A[mxN], S[mxN];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N >> X;
        for(int i=1;i<=N;i++)   cin >> A[i];
        S[0]=0;
        for(int i=1;i<=N;i++)   S[i]=S[i-1]+A[i];
        if(S[N]==X)
        {
            cout << "NO" << '\n';
            continue;
        }
        bool ok=false;
        for(int i=1;i<N;i++)
        {
            if(S[i]==X)
            {
                ok=true;
                swap(A[i], A[i+1]);
                cout << "YES" << '\n';
                for(int j=1;j<=N;j++)   cout << A[j] << " ";
                cout << '\n';
                break;
            }
        }
        if(!ok)
        {
            cout << "YES" << '\n';
            for(int i=1;i<=N;i++)   cout << A[i] << " ";
            cout << '\n';
        }
    }
}