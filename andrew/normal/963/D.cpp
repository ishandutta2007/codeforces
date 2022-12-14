#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int z[MAXN];
ll ans[MAXN];

vector <int> p[MAXN];

struct node{
    int pos;
    node *p[26];
    node(): pos(-1){
        for(int i = 0; i < 26; i++)p[i] = nullptr;
    }
};

node *root = new node();

void addB(string &s, int pos){
    node *q = root;
    for(auto i : s){
        if(q -> p[i - 'a'] == nullptr){
            q -> p[i - 'a'] = new node();
        }
        q = q -> p[i - 'a'];
    }
    q -> pos = pos;
}

void f(string &s, int i){
    node *q = root;
    int old = i;
    for(; i < s.size(); i++){
        if(q -> p[s[i] - 'a'] == nullptr)return;
        q = q -> p[s[i] - 'a'];
        if(q -> pos != -1)p[q -> pos].p_b(old);
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    ll n;
    cin >> n;
    vector < pair <ll, string> > a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i].fi >> a[i].se;
    }

    ll buben = 320;
    string S;

    for(int i = 0; i < n; i++){
        if(a[i].se.size() > buben){
            S = a[i].se + s;
            z[0] = 1e9;
            int m = S.size();
            for(int i = 1, l = 0, r = 0; i < m; i++){
                z[i] = 0;
                if(i <= r)z[i] = min(z[i - l], r - i + 1);
                while(i + z[i] < m && S[z[i]] == S[i + z[i]])++z[i];
                if(i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
            }
            vector <ll> p;
            for(int j = a[i].se.size(); j < m; j++)if(z[j] >= a[i].se.size())p.p_b(j - a[i].se.size());
            if(p.size() < a[i].fi){
                ans[i] = -1;
            }else{
                ans[i] = 1e18;
                for(int j = 0; j < p.size() - a[i].fi + 1; j++)ans[i] = min(ans[i], p[j + a[i].fi - 1] - p[j] + a[i].se.size());
            }
        }else{
            addB(a[i].se, i);
        }
    }

    for(int i = 0; i < s.size(); i++){
        f(s, i);
    }

    for(int i = 0; i < n; i++){
        if(a[i].se.size() <= buben){
            if(p[i].size() < a[i].fi){
                ans[i] = -1;
            }else{
                ans[i] = 1e18;
                for(int j = 0; j < p[i].size() - a[i].fi + 1; j++)ans[i] = min(ans[i], ll(p[i][j + a[i].fi - 1] - p[i][j] + a[i].se.size()));
            }
        }
        cout << ans[i] << "\n";
    }



    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}