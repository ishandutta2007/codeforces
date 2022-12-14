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
const int mxN=250010;
const int mxK=100000;
const ll MOD=1000000007;
const ll INF=100000000000001;
int N;
int A[mxN];
int S[mxN];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=1;i<=N;i++)   cin >> A[i];
        S[0]=0;
        for(int i=1;i<=N;i++)   S[i]=S[i-1]^A[i];
        if(S[N]==0)
        {
            cout << "YES" << '\n';
            continue;
        }
        if(N==2)
        {
            cout << "NO" << '\n';
            continue;
        }
        bool a1=false, a2=false;
        for(int i=1;i<N;i++)
        {
            if(!a1)
            {
                if(S[i]==S[N])  a1=true;
            }
            else
            {
                if(S[i]==0) a2=true;
            }
        }
        if(a2)  cout << "YES" << '\n';
        else    cout << "NO" << '\n';

    }
}