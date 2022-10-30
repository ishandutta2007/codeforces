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
#define N 100010
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
bool noww[N];
main(){
    FAST;
    ll maxres = 0, nowres = 0, n;
    cin >> n;
    for(ll i =0;i<2*n;i++){
        ll a;
        cin >> a;
        if(noww[a]){
            nowres--;
            noww[a] = false;
        }else{
            noww[a] = true;
            nowres++;
        }
        maxres = max(maxres, nowres);
    }
    cout << maxres;
}