#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200005
#define INF 101111111111111
using namespace std;
ll r[N];
int main(){
    FAST;
    string a, b;
    cin >> a >> b;
    ll n = a.length(), m = b.length();
    for(ll i = n-1, j = m-1;i>=0;i--){
        if(a[i] == b[j]){
            r[j] = i;
            j--;
        }
    }
    ll maxpref = 0, res = 0;
    for(ll i = 0;i<n;i++){
        res = max(res, (maxpref < m ? r[maxpref] : n)-i);
        if(maxpref <  m && a[i] == b[maxpref]) maxpref++;
    }
    cout << res;
}