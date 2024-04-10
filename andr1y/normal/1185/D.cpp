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
#define N 200000
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
pll a[N];
ll n;
bool check0(){
    ll d = 0;
    for(ll i = 0;i<n-1;i++){
        if(i == 0){
            d = a[i+1].x-a[i].x;
        }else{
            if(a[i+1].x-a[i].x != d) return false;
        }
    }
    return true;
}
bool check1(){
    ll d = 0;
    for(ll i = 1;i<n-1;i++){
        if(i == 1){
            d = a[i+1].x-a[i].x;
        }else{
            if(a[i+1].x-a[i].x != d) return false;
        }
    }
    return true;
}
bool check2(){
    ll d = 0;
    for(ll i = 0;i<n-1;i++){
        if(i == 1) continue;
        if(i == 0){
            d = a[i+2].x-a[i].x;
        }else{
            if(a[i+1].x-a[i].x != d) return false;
        }
    }
    return true;
}
main(){
    FAST;
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> a[i].x;
        a[i].y = i;
    }
    sort(a, a+n);
    if(check0()){
        cout << a[0].y+1;
    }else{
        bool x1 = check1(), x2 = check2();
        if(!x1 && !x2){
            ll d = a[1].x - a[0].x;
            ll fnd = -1, error = 0;
            for(ll i = 1;i<n-1;i++){
                if(a[i+1].x-a[i].x != d){
                    if((i+2 < n && a[i+2].x-a[i].x == d) || (i+2 >= n)){
                        if(fnd == -1){
                            fnd = i+1;
                        }else{
                            error = 1;
                        }
                        i+=2;
                    }else{
                        error = 1;
                    }
                }
            }
            if(error == 1){
                cout << -1;
            }else{
                cout << a[fnd].y+1;
            }
        }else{
            if(x1){
                cout << a[0].y+1;
            }else if(x2){
                cout << a[1].y+1;
            }
        }
    }
}