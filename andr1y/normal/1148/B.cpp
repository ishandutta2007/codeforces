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
#define N 200001
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
ll a[N], b[N];
ll c[N], d[N];
main(){
    FAST;
    ll n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    for(ll i =0;i<n;i++) cin >> a[i];
    for(ll i =0;i<m;i++) cin >> b[i];
    for(ll i =0, p = 0;i<n;i++){
        while(p < m && a[i]+ta > b[p]) p++;
        c[i] = p;
    }
    /*for(ll i =0, p = 0;i<m;i++){
        while(p < n && b[i]-ta >= a[p]) p++;
        p--;
        d[i] = p;
    }*/
    if(c[0] == m || k >= n || k >= m){
        cout << -1;
        exit(0);
    }
    /*ll minused = 0, p2 = c[0], p1 = 0, l = b[c[0]];
    while(p1 < n && p2 < m && minused < k){
        ll v1p = b[c[p1+1]] - b[c[p1]];
        ll v2p = b[p2+1] - b[p2];
        if(p1 == n-1) {p1++; break;}
        if(p2 == m-1) {p2++; break;}
        if(v1p > v2p){
            p1++;
            minused++;
            l += v1p;
            p2 = max(c[p1], p2);
        }else if(v2p > v1p){
            p2++;
            minused++;
            l += v2p;
            //p1 = max(p1, d[p2]);
            if(d[p2] < p1) {cout << -1;exit(0);}
        }else if(v1p == v2p){
            if(minused == k-1){
                p1++;
                l += v1p;
                minused++;
                break;
            }
            p1++;
            p2++;
            p2 = max(p2, c[p1]);
            l = b[p2];
            minused+=2;
        }
    }*/
    ll minused = 0, p2 = c[0], p1 = 0, maxres = 0;
    while(minused <= k){
        if(p1 >= n) {cout << -1;exit(0);}
        p2 = c[p1] + k - minused;
        if(p2 >= m) {cout << -1;exit(0);}
        maxres = max(maxres, b[p2]+tb);
        p1++;
        minused++;
    }
    cout << maxres;
}