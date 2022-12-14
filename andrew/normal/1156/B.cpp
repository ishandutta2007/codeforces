#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double
#define sset ordered_set
#define sqr(x) (x)*(x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const ll MAXN = 1123456;
const ll MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)(res *= a) %= MOD;
        (a *= a) %= MOD;
        n >>= 1;
    }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("twohorse.in","r",stdin);
    //freopen("twohorse.out","w",stdout);

    ll q;
    cin >> q;
    while(q--){
        vector <ll> p(26);
        string d;
        cin >> d;
        for(auto i : d)p[i - 'a']++;
        string s;
        for(int i = 0; i < 26; i += 2){
            for(int j = 0; j < p[i]; j++)s += char(i + 'a');
        }
        bool fl = 0, f = 0;
        vector <ll> kek;
        for(int i = 1; i < 26; i += 2){
            if(p[i]){
                f = 1;
                if(s.empty())fl = 1;
                else if(abs(s[s.size() - 1] - 'a' - i) > 1)fl = 1;
                if(fl)for(int j = 0; j < p[i]; j++)s += char(i + 'a');else kek.p_b(i);
            }
        }

        if(kek.size() && fl){
            for(auto i : kek)
                for(int j = 0; j < p[i]; j++)s += char(i + 'a');
            cout << s << "\n";
        }else if(kek.empty()){
            cout << s << "\n";
        }else{
            s.clear();
            for(int i = 1; i < 26; i += 2){
                for(int j = 0; j < p[i]; j++)s += char(i + 'a');
            }
            bool fl = 0, f = 0;
            vector <ll> kek;
            for(int i = 0; i < 26; i += 2){
                if(p[i]){
                    f = 1;
                    if(s.empty())fl = 1;
                    else if(abs(s[s.size() - 1] - 'a' - i) > 1)fl = 1;
                    if(fl)for(int j = 0; j < p[i]; j++)s += char(i + 'a');else kek.p_b(i);
                }
            }
            if(kek.size() && fl){
                for(auto i : kek)
                    for(int j = 0; j < p[i]; j++)s += char(i + 'a');
                cout << s << "\n";
            }else if(kek.empty()){
                cout << s << "\n";
            }else cout << "No answer\n";
        }

    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}