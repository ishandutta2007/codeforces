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
ll N;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        if(N<=4)
        {
            if(N==1 || N==3)    cout << "NO" << '\n';
            else    cout << "YES" << '\n';
            continue;
        }
        ll now=1;
        while(4*(now+1)*(now+1)<=N)   now++;
        if(4*now*now==N)
        {
            cout << "YES" << '\n';
            continue;
        }
        now=1;
        while(2*(now+1)*(now+1)<=N) now++;
        if(2*now*now==N)
        {
            cout << "YES" << '\n';
            continue;
        }
        cout << "NO" << '\n';
    }
}