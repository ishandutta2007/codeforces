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
#define N 20005
#define INF 101111111111111
using namespace std;
ll a[N];
ll b[N];
ll np[N], npc = 0;
main(){
    FAST;
    ll n, xs= 0 ;
    cin >> n;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
        if(a[i]%2 == 0) b[i] = a[i]/2;
        else{
            np[npc++] = i;
            b[i] = a[i]/2;
            if(a[i] < 0) b[i]--;
        }
        xs += b[i];
    }
    ll xc = 0;
    while(xs < 0 && xc < npc){
        b[np[xc++]]++, xs++;
    }
    for(ll i =0;i<n;i++) cout << b[i] << endl;
}