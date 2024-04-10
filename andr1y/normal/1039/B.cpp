#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
main(){
    srand(99824);
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = n;
    while(true){
        while(r - l > 50){
            ll m = (l + r)>>1;
            cout << l << " " << m << endl;
            cout.flush();
            string res;
            cin >> res;
            if(res[0] == 'Y'){
                r = m;
            }else{
                l = m;
            }
            l = max(1ll, l-k);
            r = min(n, r+k);
        }
        while(r - l <= 50){
            ll goo = l + rand()%(r-l+1);
            if(goo > n) goo--;
            cout << goo << " " << goo << endl;
            cout.flush();
            string res;
            cin >> res;
            if(res[0] == 'Y') exit(0);
            l = max(1ll, l-k);
            r = min(n, r+k);
        }
    }
}