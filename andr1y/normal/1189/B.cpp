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
#define N 100000
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
ll a[N];
ll b[N];
ll st = 0, en = 0;
main(){
    FAST;
    ll n;
    cin >> n;
    en = n-1;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);
    b[st++] = a[0];
    b[st++] = a[1];
    b[en--] = a[2];
    for(ll i = 3;i<n-1;i+=2){
        b[st++] = a[i];
        b[en--] = a[i+1];
    }
    if(n%2 == 0) b[st] = a[n-1];
    bool ok = true;
    for(ll i = 0;i<n;i++){
        if(i == 0){
            ok = ok && (b[n-1] + b[1] > b[0]);
        }else if(i == n-1){
            ok = ok && (b[0] + b[n-2] > b[n-1]);
        }else{
            ok = ok && (b[i-1] + b[i+1] > b[i]);
        }
    }
    if(ok){
        cout << "YES" << endl;
        for(ll i =0;i<n;i++) cout << b[i] << " ";
    }else{
        cout << "NO" << endl;
    }
}