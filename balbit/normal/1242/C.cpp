#include <bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
#define REP(i,n) for(int i=0; i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define SZ(i) int(i.size())
#define eb emplace_back
#ifdef BTC
#define IOS()
#define debug(...) fprintf(stderr,"%s - %d (%s) =",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y) {cerr<<x<<",";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(...)
#define endl '\n'
#endif // BTC
const int MAXN = 16;
const ll INF = 0x3f3f3f3f3f3f3f3f;

/*********GOOD_LUCK**************/

int k, s[MAXN], sum;
vector<int> a[MAXN];
map<int,int> id;
bool vis[MAXN];
bool fll[MAXN];
int ci, cj;
int c[MAXN], p[MAXN];
int tc[MAXN], tp[MAXN];

bool dp[1<<MAXN];
int tran[1<<MAXN];
pair<int,int> st[1<<MAXN];

pair<int,int> root;

int msk;
bool dfs (int nd, int val) {
    if (vis[nd]) {
        if (nd == root.first && val == root.second) {
            return true;
        } else {
            return false;
        }
    }
    vis[nd] = true;
    msk |= 1<<nd;

    int nval = val + (sum - s[nd]);
    if(id.count(nval) == 0) {
        return false;
    } else {
        int gp = id[nval];
        tc[gp] = nval;
        tp[gp] = nd;
        return dfs(gp, nval);
    }

}

void build_ans (int mk) {
    if (tran[mk] == -2) {
        return;
    } else if (tran[mk] == -1) {
        memset(vis, 0, sizeof(vis));
        dfs(st[mk].first, st[mk].second);
        REP (i, k) {
            if (vis[i]) {
                c[i] = tc[i];
                p[i] = tp[i];
            }
        }
    } else {
        build_ans(tran[mk]);
        build_ans(mk^tran[mk]);
    }
}
signed main () {
    IOS();

    cin >>k;

    sum = 0;
    REP (i, k) {
        int sz;
        cin >>sz;
        REP (j, sz) {
            int d;
            cin >> d;
            sum += d;
            s[i] += d;
            a[i].eb(d);
            id[d] = i;
        }
    }

    if (sum % k != 0) {
        cout << "No" << endl;
    } else {
        sum /= k;
        int dcnt = 0;
        REP (i, k) {
            if (s[i] == sum) {
                dcnt++;
                fll[i] = true;
                c[i] = a[i][0];
                p[i] = i;
                dp[1<<i] = true;
                tran[1<<i] = -2;
            }
        }

        REP (i, k) {
            REP (j, SZ(a[i])) {
                if (s[i] == sum) {
                    continue;
                }

                memset(vis, 0, sizeof(vis));
                root = make_pair(i, a[i][j]);
                msk = 0;

                bool b = dfs(i, a[i][j]);

                debug(i, j);

#ifdef BTC
                if (b) {
                    REP (t, k) {
                        if (vis[t]) {
                            debug(t, tc[t], tp[t]);
                        }
                    }
                }

#endif // BTC
                if (b) {
                    dp[msk] = true;
                    tran[msk] = -1;
                    st[msk] = {i, a[i][j]};
                }
            }
        }

        REP (mk, (1<<k)) {
            if (dp[mk]) {
                continue;
            }
            for (int ss=mk; ss>0; ss=(ss-1)&mk) {
                if (dp[ss] && dp[mk^ss]) {
                    dp[mk] = true;
                    tran[mk] = ss;
                    break;
                }
            }
        }

        if (dp[(1<<k)-1]) {
            build_ans((1<<k)-1);

            cout << "Yes" << endl;
            REP (i, k) {
                cout <<c[i] << " " << p[i] + 1 << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }


    return 0;
}