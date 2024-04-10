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
pll a[N];
ll n;
void out(){
    sort(a, a+n, [](pll x, pll y){return x.y < y.y;});
    for(ll i =0;i<n;i++) cout << a[i].x << " ";
    exit(0);
}
main(){
    FAST;
    cin >> n;
    for(ll i =0;i<n;i++){
        cin >> a[i].x;
        a[i].y = i;
    }
    ll adob = 1;
    for(ll i =0;i<n;i++){
        if(a[i].x >= 0) a[i].x = -a[i].x-1;
        adob*=a[i].x;
    }
    if((n&1) == 0){
        out();
    }else{
        sort(a, a+n);
        bool fnd = 0;
        for(ll i = 0;i<n;i++){
            if(a[i].x <= -2){
                a[i].x = -a[i].x-1;
                fnd = true;
                break;
            }
        }
        if(!fnd){
            for(ll i = 0;i<n;i++){
                if(a[i].x <= -1){
                    a[i].x = -a[i].x-1;
                    fnd = true;
                    break;
                }
            }
            out();
        }else out();
    }
}