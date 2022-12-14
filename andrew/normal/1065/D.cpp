#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef int ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

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

vector <pll> sg[3];

ll b[11][11][6][3], n;
ll bb[11][11][3][11][11][6][3];
ll dp[110][303][3];

pll a[101];
priority_queue <pair<ll, pair<pll, pair<ll, pll> > > > q;

void add(ll y, ll x, ll izm, ll fig, ll vall){
    if(y < 1 || x < 1 || y > n || x > n || izm > 5)return;
    if(b[y][x][izm][fig] <= vall)return;
    b[y][x][izm][fig] = vall;
    q.push({-vall, m_p(m_p(y, x), m_p(0ll, m_p(izm, fig) ) )});
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;

    sg[0].p_b({2, 1});
    sg[0].p_b({2, -1});
    sg[0].p_b({-2, -1});
    sg[0].p_b({-2, 1});
    sg[0].p_b({1, 2});
    sg[0].p_b({1, -2});
    sg[0].p_b({-1, -2});
    sg[0].p_b({-1, 2});


    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
        ll x;
        cin >> x;
        a[x] = {i, j};
    }
    ll i,j, i1, j1, ii1;
    for(int yy = 1; yy <= n; yy++)
        for(int xx = 1; xx <= n; xx++)
        for(int i1 = 0; i1 < 3; i1++)
        for(i = 1; i <= n; i++)
                    for(j = 1; j <= n; j++)
                    for(j1 = 0; j1 < 6; j1++)
                    for(ii1 = 0; ii1 < 3; ii1++)bb[yy][xx][i1][i][j][j1][ii1] = 1e9;

    for(int yy = 1; yy <= n; yy++)
    for(int xx = 1; xx <= n; xx++){
            for(int i1 = 0; i1 < 3; i1++){

                for(i = 1; i <= n; i++)
                    for(j = 1; j <= n; j++)
                        for(j1 = 0; j1 < 6; j1++)
                            for(ii1 = 0; ii1 < 3; ii1++)b[i][j][j1][ii1] = 1e9;

                add(yy, xx, 0, i1, 0);
                while(!q.empty()){
                    pair<ll, pair<pll, pair<ll, pll> > >  xe = q.top();
                    q.pop();
                    ll y = xe.se.fi.fi, x = xe.se.fi.se,  izm = xe.se.se.se.fi, fig = xe.se.se.se.se, val = b[y][x][izm][fig];

                    for(int i = 0; i < 3; i++)if(i != fig)add(y, x, izm + 1, i, val + 1);

                    bool fl = 0;
                    if(fig == 0){
                        for(auto i : sg[0])add(y + i.fi, x + i.se, izm, fig, val + 1);
                    }
                    if(fig == 1){
                        for(i = 1; i <= n; i++){
                            add(y + i, x + i, izm, fig, val + 1);
                            add(y + i, x - i, izm, fig, val + 1);
                            add(y - i, x + i, izm, fig, val + 1);
                            add(y - i, x - i, izm, fig, val + 1);
                        }
                    }
                    if(fig == 2){
                        for(i = 1; i <= n; i++){
                            add(y + i, x, izm, fig, val + 1);
                            add(y - i, x, izm, fig, val + 1);
                            add(y, x + i, izm, fig, val + 1);
                            add(y, x - i, izm, fig, val + 1);
                        }
                    }

                }

                for(i = 1; i <= n; i++)
                    for(j = 1; j <= n; j++)
                    for(j1 = 0; j1 < 6; j1++)
                    for(ii1 = 0; ii1 < 3; ii1++)bb[yy][xx][i1][i][j][j1][ii1] = min(bb[yy][xx][i1][i][j][j1][ii1], b[i][j][j1][ii1]);

            }
    }



    for(int i = 1; i <= n * n; i++){
        for(int j = 0; j <= 303; j++)dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 1e9;
    }

    ll y = a[1].fi, x = a[1].se;
    for(int yy = 1; yy <= n; yy++)
    for(int xx = 1; xx <= n; xx++)
    for(int i1 = 0; i1 < 3; i1++)
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 3; j++)dp[1][i][j] = min(dp[1][i][j], bb[yy][xx][i1][y][x][i][j]);

    for(int i = 2; i <= n * n; i++){
        ll y = a[i].fi, x = a[i].se;
        ll old_y = a[i - 1].fi, old_x = a[i - 1].se;
        for(int j = 0; j < 3; j++)
            for(int was = 0; was < 3; was++)
                for(int jj = 0; jj < 303; jj++)
                for(int j1 = 0; j1 < 6; j1++)if(dp[i - 1][jj][was] != 1e9 &&  bb[old_y][old_x][was][y][x][j1][j] != 1e9){
                    //cout << i << " " << jj + i1 << "\n";
                    if(jj + j1 < 303)dp[i][jj + j1][j] = min(dp[i][jj + j1][j], dp[i - 1][jj][was] + bb[old_y][old_x][was][y][x][j1][j]);
            }

    }

    ll ans = 1e9;
    for(int i = 0; i < 303; i++)
        for(int j = 0; j < 3; j++)ans = min(ans, dp[n * n][i][j]);

    ll mx = 1e9;
    for(int i = 0; i < 303; i++)
        for(int j = 0; j < 3; j++)if(ans == dp[n * n][i][j])mx = min(mx, i);

    cout << ans << " " << mx << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}