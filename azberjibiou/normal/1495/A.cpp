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
const int mxN=100100;
const int mxM=250100;
const ll mxK=2500;
const ll MOD=1000000007;
const ll INF=1000000000000000001;
int N;
vector <ll> X, Y;
long double ans;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        X.clear();
        Y.clear();
        ans=0;
        cin >> N;
        for(int i=1;i<=2*N;i++)
        {
            int x, y;
            cin >> x >> y;
            if(x==0)    X.push_back(abs(y));
            else    Y.push_back(abs(x));
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        for(int i=0;i<N;i++)
        {
            ll tmp=X[i]*X[i]+Y[i]*Y[i];
            ans+=(long double)sqrt(tmp);
        }
        cout.precision(16);
        cout << ans << '\n';
    }
}