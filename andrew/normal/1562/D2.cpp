#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 4e5 + 5;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const int mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <int> v[M];

void solve(){
    int n, q;
    cin >> n >> q;
    vector <int> pref(n + 1);
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        int x = 1;
        if(c == '-')x = -1;
        if(i % 2 == 0)x *= -1;
        pref[i] = pref[i - 1] + x;
        v[pref[i] + N].p_b(i);
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        int x = pref[r] - pref[l - 1];
        if(x == 0){
            cout << "0\n";
            continue;
        }
        int c = x;
        x %= 2;
        if(x){
            cout << "1\n";
            ll val = 1;
            if(c < 0)val = -1;
            cout << *lower_bound(all(v[N + pref[l - 1] + c / 2 + val]), l) << "\n";
        }else{
            cout << "2\n" << l << " ";
            l++;
            c = pref[r] - pref[l - 1];
            ll val = 1;
            if(c < 0)val = -1;
            cout << *lower_bound(all(v[N + pref[l - 1] + c / 2 + val]), l) << "\n";
        }
    }



    for(int i = -n; i <= n; i++){
        v[i + N].clear();
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
14 1
+--++---+++---
6 12
*/