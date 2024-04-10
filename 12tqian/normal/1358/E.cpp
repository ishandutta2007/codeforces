#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma optimize(O3);
using namespace std;
using namespace __gnu_pbds;
//template <class T> Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_node_order_statistics>;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vpl;
typedef vector<ld> vd;
typedef vector<pair<ld, ld>> vpd;
typedef vector<pair<int, int>> vpi;

#define f0r(i,a) for(int i = (0); i<(a); ++i)
#define f1r(i,a,b) for(int i = (a); i<(b); ++i)
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define sz(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MAX = 5e5 + 5;
ll a[MAX];
ll pre[MAX];
inline ll sum(int l, int r){
    return pre[r] - (l == 0? 0: pre[l-1]);
}
ll vals[MAX];
ll premin[MAX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    f0r(i, (n+1)/2) cin >> a[i];
    ll x; cin >> x;
    f1r(i, (n+1)/2, n) a[i] = x;
    f0r(i, n){
        if(i == 0) pre[i] = a[i];
        else pre[i] = pre[i-1] + a[i];
    }
    if(sum(0, n-1)>0){
        cout << n << endl;
        return 0;
    }
    if(x>0){
        cout << -1 << endl;
        return 0;
    }
    set<ll> s;
    for(int i =  (n-1)/2; i>= 0; i--){
        ll val = sum(i, (n-1)/2);
        if(x == 0){
            if(val<=0){
                cout << -1 << endl;
                return 0;
            }
            continue;
        }

        vals[i] = (min((val-1)/(-x), (ll) n/2) + (n-1)/2 - i +1);
    }

    if(x == 0){
        assert(false);
    }
    f0r(i, n){
        if(i == 0) premin[i] = vals[i];
        else premin[i] = min(premin[i-1], vals[i]);
    }
    f0r(i, (n+1)/2){
        if(n-1 - i+1 <= premin[i]){
            cout << n-1-i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}