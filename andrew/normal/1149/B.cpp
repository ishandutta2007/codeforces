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
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int dp[251][251][251];

int _next[100100][26];

vector <int> v[26];
int uk[26];

int n, q;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> q;
    string s;
    cin >> s;

    for(int i = 0; i < n; i++){
        v[s[i] - 'a'].p_b(i + 1);
    }

    for(int i = 0; i < 26; i++)v[i].p_b(2e9);

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 26; j++){
            while(v[j][uk[j]] <= i)uk[j]++;
            _next[i][j] = v[j][uk[j]];
        }
    }

    for(int i = 0; i < 251; i++)
        for(int j = 0; j < 251; j++)
        for(int i1 = 0; i1 < 251; i1++)dp[i][j][i1] = 2e9;

    dp[0][0][0] = 0;

    string a, b, c;

    for(int step = 0; step < q; step++){
        char t;
        cin >> t;
        if(t == '+'){
            ll x;
            cin >> x >> t;
            if(x == 1){
                ll k = a.size();

                for(int i = 0; i <= b.size(); i++)
                for(int j = 0; j <= c.size(); j++)if(dp[k][i][j] != 2e9){
                    dp[k + 1][i][j] = min(dp[k + 1][i][j], _next[dp[k][i][j]][t - 'a']);
                }

                a += t;
                k = a.size();

                for(int i = 0; i <= b.size(); i++)
                for(int j = 0; j <= c.size(); j++)if(dp[k][i][j] != 2e9){
                    if(i < b.size()){
                        dp[k][i + 1][j] = min(dp[k][i + 1][j], _next[dp[k][i][j]][b[i] - 'a']);
                    }
                    if(j < c.size()){
                        dp[k][i][j + 1] = min(dp[k][i][j + 1], _next[dp[k][i][j]][c[j] - 'a']);
                    }
                }


            }else if(x == 2){
                ll k = b.size();

                for(int i = 0; i <= a.size(); i++)
                for(int j = 0; j <= c.size(); j++)if(dp[i][k][j] != 2e9){
                    dp[i][k + 1][j] = min(dp[i][k + 1][j], _next[dp[i][k][j]][t - 'a']);
                }

                b += t;
                k = b.size();

                for(int i = 0; i <= a.size(); i++)
                for(int j = 0; j <= c.size(); j++)if(dp[i][k][j] != 2e9){
                    if(i < a.size()){
                        dp[i + 1][k][j] = min(dp[i + 1][k][j], _next[dp[i][k][j]][a[i] - 'a']);
                    }
                    if(j < c.size()){
                        dp[i][k][j + 1] = min(dp[i][k][j + 1], _next[dp[i][k][j]][c[j] - 'a']);
                    }
                }


            }else if(x == 3){
                ll k = c.size();

                for(int i = 0; i <= a.size(); i++)
                for(int j = 0; j <= b.size(); j++)if(dp[i][j][k] != 2e9){
                    dp[i][j][k + 1] = min(dp[i][j][k + 1], _next[dp[i][j][k]][t - 'a']);
                }

                c += t;
                k = c.size();

                for(int i = 0; i <= a.size(); i++)
                for(int j = 0; j <= b.size(); j++)if(dp[i][j][k] != 2e9){
                    if(i < a.size()){
                        dp[i + 1][j][k] = min(dp[i + 1][j][k], _next[dp[i][j][k]][a[i] - 'a']);
                    }
                    if(j < b.size()){
                        dp[i][j + 1][k] = min(dp[i][j + 1][k], _next[dp[i][j][k]][b[j] - 'a']);
                    }
                }
            }
        }else{
            ll pos;
            cin >> pos;
            if(pos == 1){
                for(int i = 0; i <= b.size(); i++)
                    for(int j = 0; j <= c.size(); j++)dp[a.size()][i][j] = 2e9;
                a.erase(a.size() - 1);
            }else if(pos == 2){
                for(int i = 0; i <= a.size(); i++)
                    for(int j = 0; j <= c.size(); j++)dp[i][b.size()][j] = 2e9;
                b.erase(b.size() - 1);
            }else if(pos == 3){
                for(int i = 0; i <= a.size(); i++)
                    for(int j = 0; j <= b.size(); j++)dp[i][j][c.size()] = 2e9;
                c.erase(c.size() - 1);
            }
        }
        if(dp[a.size()][b.size()][c.size()] <= n)cout << "YES\n"; else cout << "NO\n";
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}