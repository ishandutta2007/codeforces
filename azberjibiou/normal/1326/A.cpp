#include<bits/stdc++.h>
#define gibon cin.tie(0); ios::sync_with_stdio(false);
#define fir first
#define sec second
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long int ll;
const ll MOD=1000000007;
const ll INF=10000000000007;
int main()
{
    gibon
    int T;
    cin >> T;
    int N;
    while(T--)
    {
        cin >> N;
        if(N==1)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << 2;
            for(int i=0;i<N-1;i++)  cout << 3;
            cout << '\n';
        }
    }
}