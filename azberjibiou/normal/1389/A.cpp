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
const int mxN=301000;
const int mxM=2100000;
const ll MOD=1000000007;
const ll INF=1000000000000;
int N;
int main()
{
    gibon
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        if(b%2!=0)  b--;
        if(b/2<a)   cout << "-1 -1\n";
        else    cout << b/2 << " " << b << '\n';
    }
}