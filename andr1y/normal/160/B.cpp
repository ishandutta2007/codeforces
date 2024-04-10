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
#define N 100
#define INF 101111111111111
using namespace std;
ll part[2][N];
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        char c;
        cin >> c;
        part[0][i] = c-'0';
    }
    for(ll i = 0;i<n;i++){
        char c;
        cin >> c;
        part[1][i] = c-'0';
    }
    sort(part[0], part[0]+n);
    sort(part[1], part[1]+n);
    bool isbig = part[0][0] > part[1][0];
    bool res= true;
    for(ll i = 0;i<n;i++){
        if(part[0][i] == part[1][i]){
            res = false;
            break;
        }
        res = res & ((isbig && part[0][i] > part[1][i]) || (!isbig && part[0][i] < part[1][i]));
    }
    cout << (res ? "YES" : "NO");
}