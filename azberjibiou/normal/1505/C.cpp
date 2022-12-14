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
const int mxN=201000;
const int mxM=10000100;
const ll mxK=2500;
const int MOD=998244353;
const ll INF=1000000000000000001;
char S[mxN];
int main()
{
    gibon
    cin >> S;
    int N=strlen(S);
    for(int i=2;i<N;i++)
    {
        if(S[i]-'A'!=(S[i-1]-'A'+S[i-2]-'A')%26)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}