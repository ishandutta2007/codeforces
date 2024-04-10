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
#define N 2001
#define INF 101111111111111
using namespace std;
map<ll, ll> cnt;
ll a[N];
int main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++) cin >> a[i];
    ll res = INF;
    for(ll i = 0;i<n;i++){
        map<ll, ll> xcnt;
        for(ll j = n-1;j>=i;j--){
            if(cnt[a[j]]+xcnt[a[j]] > 0){
                res = min(res, j-i+1);
                break;
            }
            xcnt[a[j]]++;
        }
        if(cnt[a[i]] > 0){
            break;
        }
        cnt[a[i]]++;
    }
    cout << res%INF;
}