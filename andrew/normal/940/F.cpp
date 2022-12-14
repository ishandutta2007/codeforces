#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
const ll N = 2e6;
const ll inf = 2e9;
const ll M = 300000;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector <ll> ans, p, where, a, old;

ll buben = 2000;

struct zp{
    ll t, w, l, r, fufel;
};

vector <zp> b;

bool cmp(ll a, ll a1){
    return (m_p(m_p(b[a].t / buben, b[a].l / buben), m_p(((b[a].l / buben) & 1 ? b[a].r : -b[a].r), a))
            <
            m_p(m_p(b[a1].t / buben, b[a1].l / buben), m_p(((b[a1].l / buben) & 1 ? b[a1].r : -b[a1].r), a1)));
}

ll cnt_now[MAXN], cnt_cnt[MAXN];


void add(int pos){
    cnt_cnt[cnt_now[a[pos]]]--;
    cnt_now[a[pos]]++;
    cnt_cnt[cnt_now[a[pos]]]++;
}

void del(int pos){
    cnt_cnt[cnt_now[a[pos]]]--;
    cnt_now[a[pos]]--;
    cnt_cnt[cnt_now[a[pos]]]++;
}

int l = 1, r = 1, t_now;

void add_t(int type){
    int x = where[type], pos = b[x].l;

    if(l <= pos && pos <= r){
        cnt_cnt[cnt_now[a[pos]]]--;
        cnt_now[a[pos]]--;
        cnt_cnt[cnt_now[a[pos]]]++;
        a[pos] = b[x].r;
        cnt_cnt[cnt_now[a[pos]]]--;
        cnt_now[a[pos]]++;
        cnt_cnt[cnt_now[a[pos]]]++;
    }
    a[pos] = b[x].r;
}

void del_t(int type){
    int x = where[type], pos = b[x].l;

    if(l <= pos && pos <= r){
        cnt_cnt[cnt_now[a[pos]]]--;
        cnt_now[a[pos]]--;
        cnt_cnt[cnt_now[a[pos]]]++;
        a[pos] = b[x].w;
        cnt_cnt[cnt_now[a[pos]]]--;
        cnt_now[a[pos]]++;
        cnt_cnt[cnt_now[a[pos]]]++;
    }
    a[pos] = b[x].w;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, k;
    cin >> n >> k;

    a.resize(n + 1);

    map <ll, ll> mp;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(mp.find(a[i]) == mp.end())mp[a[i]] = sz(mp);
        a[i] = mp[a[i]];
    }
    old = a;

    ans.resize(k + 10);
    where.resize(k + 10);
    p.resize(k);
    b.resize(k + 10);

    ll stn = 0;


    for(int i = 0; i < k; i++){
        ll t;
        cin >> t;
        p[i] = i;
        b[i].fufel = t;
        if(t == 1){
            cin >> b[i].l >> b[i].r;
            b[i].t = stn;
        }else{
            stn++;
            where[stn] = i;
            cin >> b[i].l >> b[i].r;
            if(mp.find(b[i].r) == mp.end())mp[b[i].r] = sz(mp);
            b[i].r = mp[b[i].r];
            b[i].w = a[b[i].l];
            a[b[i].l] = b[i].r;
            b[i].t = stn;
            a[b[i].l] = b[i].r;
        }
    }

    sort(all(p), cmp);

    a = old;
    add(1);

    for(auto i : p){
        if(b[i].fufel == 1){
            while(l > b[i].l){
                add(--l);
            }
            while(r < b[i].r){
                add(++r);
            }
            while(l < b[i].l){
                del(l++);
            }
            while(r > b[i].r){
                del(r--);
            }
            while(t_now < b[i].t){
                add_t(++t_now);
            }
            while(t_now > b[i].t){
                del_t(t_now--);
            }
            for(int j = 1;;j++){
                if(!cnt_cnt[j]){
                    ans[i] = j;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < k; i++)if(b[i].fufel == 1){
        cout << ans[i] << "\n";
    }

    return 0;
}