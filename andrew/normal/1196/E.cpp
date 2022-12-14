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

map <pll, bool> mp;

queue <pll> q;
ll b, w;

void add(ll x, ll y){
    if(mp.find({x, y}) != mp.end())return;
    if((x + y) % 2 == 0){
        if(!w)return;
        w--;
    }else{
        if(!b)return;
        b--;
    }
    mp[{x, y}] = 1;
    q.push({x, y});
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    ll t;
    cin >> t;

    while(t--){
        cin >> b >> w;
        ll lb = b, lw = w;
        ll x = 1e9 / 2, y = 1e9 / 2;
        mp.clear();
        vector <pll> res;
        add(x, y);
        while(!q.empty()){
            pll xe = q.front();
            q.pop();
            res.p_b(xe);
            add(xe.fi - 1, xe.se);
            add(xe.fi + 1, xe.se);
            add(xe.fi, xe.se - 1);
            add(xe.fi, xe.se + 1);
        }

        if(b || w){
            res.clear();
            b = lb, w = lw;
            ll x = 1e9 / 2, y = 1e9 / 2 + 1;
            mp.clear();
            vector <pll> res;
            add(x, y);
            while(!q.empty()){
                pll xe = q.front();
                q.pop();
                res.p_b(xe);
                add(xe.fi - 1, xe.se);
                add(xe.fi + 1, xe.se);
                add(xe.fi, xe.se - 1);
                add(xe.fi, xe.se + 1);
            }
            if(b || w){
                w = lw, b = lb;
                ll d = min(w, b);
                if(w == b){
                    cout << "YES\n";
                    for(int i = 1; i <= w + b; i++)cout << "1 " << i << "\n";
                    continue;
                }
                if(w > b){
                    ll x, y;
                    x = 4, y = 3;
                    vector <pll> res;
                    w -= d;
                    b -= d;
                    for(int i = 1; i <= d * 2; i++){
                        res.p_b({x, y});
                        if((x + y) % 2 && w){
                            w--;
                            res.p_b({x, y - 1});
                        }
                        if((x + y) % 2 && w){
                            w--;
                            res.p_b({x, y + 1});
                        }
                        if(i == 1 && w){
                            res.p_b({x - 1, y});
                            w--;
                        }
                        x++;
                    }
                    if(!w){
                        cout << "YES\n";
                        for(auto i : res)cout << i.fi << " " << i.se << "\n";
                        continue;
                    }
                    cout << "NO\n";
                    continue;
                }

                if(w < b){
                    ll x, y;
                    x = 3, y = 3;
                    vector <pll> res;
                    w -= d;
                    b -= d;
                    for(int i = 1; i <= d * 2; i++){
                        res.p_b({x, y});
                        if((x + y) % 2 == 0 && b){
                            b--;
                            res.p_b({x, y - 1});
                        }
                        if((x + y) % 2 == 0 && b){
                            b--;
                            res.p_b({x, y + 1});
                        }
                        if(i == 1 && b){
                            res.p_b({x - 1, y});
                            b--;
                        }
                        x++;
                    }
                    if(!b){
                        cout << "YES\n";
                        for(auto i : res)cout << i.fi << " " << i.se << "\n";
                        continue;
                    }
                    cout << "NO\n";
                    continue;
                }
            } else{
                cout << "YES\n";
                for(auto i : res)cout << i.fi << " " << i.se << "\n";
            }
        } else{
            cout << "YES\n";
            for(auto i : res)cout << i.fi << " " << i.se << "\n";
        }

    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}