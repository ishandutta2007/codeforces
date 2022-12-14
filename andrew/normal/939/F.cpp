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
#define sz(x) (int)x.size()

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 1e5;
const ll inf = 2e9;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}


class MyQueue{

    vector<pair<int,int> > a1, a2;

    void clear_a1_stack() {

        while(a1.size()) {

            a2.push_back(a1.back());


            if (a2.size() > 1) a2.back().se = min(a2.back().fi, a2[a2.size() - 2].se);
            else a2.back().se = a2.back().fi;

            a1.pop_back();
        }

    }


public:

    void push(int xx) {
        a1.push_back({xx, xx});

        if (a1.size() > 1) a1.back().se = min(a1.back().fi, a1[a1.size() - 2].se);
    }


    bool is_queue_empty() {

        if (a1.size() == 0 && a2.size() == 0) return 1;
        return 0;

    }

    void pop() {

        if (!a2.size()) clear_a1_stack();
        a2.pop_back();
    }


    int get_front() {

        if (!a2.size()) clear_a1_stack();
        return a2.back().fi;
    }


    int get_min() {

        if (!a2.size()) {
            clear_a1_stack();
        }

        int mn;
        if (a1.size()) mn = min(a1.back().se, a2.back().se);
        else mn = a2.back().se;

        return mn;

    }
};

MyQueue sa, sb;
int dp[2][2 * N + 2][2];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL

    int n, k;
    cin >> n >> k;

    vector <pii> a(k);

    for(int i = 0; i < k; i++)cin >> a[i].fi >> a[i].se;
    if(a[0].se == 0){
        a.erase(a.begin());
        k--;
    }

    //for(auto &i : a)i.fi++,i.se++;
    //if(a[k - 1].se == 2 * n + 1)a[k - 1].se--;

    for(int i = 0; i < 2; i++)
        for(int j = 0; j <= 2 * n; j++)dp[i][j][0] = dp[i][j][1] = inf;

    int old = 0;

    a.p_b({2 * n, 2 * n});

    dp[old][0][0] = 0;
    dp[old][0][1] = 0;

    int last = 0;

    for(int step = 0; step < k; step++){
        int nw = old ^ 1, kl = a[step].se - a[step].fi + 1, delta = a[step + 1].fi - a[step].se;
        int dt = a[step].fi - last;
        for(int j = 2 * n; j >= 0; j--){
            if(j < dt)dp[old][j][0] = inf;
            else dp[old][j][0] = dp[old][j - dt][0];
        }
        for(int i = 0; i < 2; i++)
            for(int j = 0; j <= 2 * n; j++)dp[nw][j][i] = inf;

        while(!sa.is_queue_empty())sa.pop();
        while(!sb.is_queue_empty())sb.pop();

        for(int i = 0; i <= a[step].se; i++){
            dp[nw][i][1] = min(dp[nw][i][1], dp[old][i][1]);
            sa.push(dp[old][i][0]);
            sb.push(dp[old][i][1]);
            if(i <= n)dp[nw][i][0] = min(dp[nw][i][0], sb.get_min() + 1);
            if(i <= n)dp[nw][i][0] = min(dp[nw][i][0], sa.get_min() + 2);
            if(i <= n)dp[nw][i][1] = min(dp[nw][i][1], sa.get_min() + 1);
            if(i <= n)dp[nw][i][1] = min(dp[nw][i][1], sb.get_min() + 2);
            if(i - kl + 1 >= 0){
                dp[nw][i][0] = min(dp[nw][i][0], dp[old][i - kl + 1][0]);
                sa.pop();
                sb.pop();
            }
        }
        old = nw;
        last = a[step].se;
    }

    int dt = 2 * n - last;

    for(int j = 2 * n; j >= 0; j--){
        if(j < dt)dp[old][j][0] = inf;
        else dp[old][j][0] = dp[old][j - dt][0];
    }

    int ans = min(dp[old][n][0], dp[old][n][1]);

    if(ans == inf)vout("Hungry");


    cout << "Full\n";
    cout << ans << "\n";

    return 0;
}