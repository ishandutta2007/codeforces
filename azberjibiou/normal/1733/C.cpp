#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pdd pair<long double, long double>
#define pii pair<int, int>
#define pll pair<ll, ll>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
using namespace std;
const int mxN=100002;
const int mxM=300000;
const int mxQ=3000010;
const ll MOD=998244353;
const ll INF=1e18;
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
int ddx[8]={1, 1, 0, -1, -1, -1, 0, 1}, ddy[8]={0, -1, -1, -1, 0, 1, 1, 1};
int N;
int A[mxN];
vector <int> one, zero;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=1;i<=N;i++)   cin >> A[i];
        zero.clear();   one.clear();
        for(int i=1;i<=N;i++)
        {
            if(A[i]%2==1)   one.push_back(i);
            else    zero.push_back(i);
        }
        if(one.empty() || zero.empty())
        {
            cout << N-1 << '\n';
            for(int i=N-1;i>=1;i--)    cout << i << " " << i+1 << '\n';
            continue;
        }
        cout << N-1 << '\n';
        if(one[0]!=1)   swap(one, zero);
        for(int i=one.size()-1;i>=1;i--)    cout << one[i-1] << " " << one[i] << '\n';
        for(int i=0;i<zero.size();i++)  cout << 1 << " " << zero[i] << '\n';
    }
}