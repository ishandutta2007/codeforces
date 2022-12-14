#include <bits/stdc++.h>

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
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 500000;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

string s;
int p[N + 5][20];
vector <pii> b;
int cnt[MAXN], pos[MAXN], stn, LCP[MAXN];
pii d[MAXN];
vector <int> v[MAXN];

void build_suffix_array(){
    ll n = s.size();
    b.resize(n + 2);
    pii last = {0, 0};
    for(auto i : s)if(i != '#')cnt[i - '('] = 1;
    for(int i = 1; i < 2; i++)cnt[i] += cnt[i - 1];
    for(int i = 0; i < n; i++){
        if(s[i] == '#')p[i][0] = cnt[1];
        else p[i][0] = cnt[s[i] - '('] - 1;
    }

    for(int step = 1; step <= 19; step++){
        for(int i = 0; i < n; i++)cnt[i] = 0;
        for(int i = n - 1; i >= 0; i--){
            ll j = i + pw(step - 1);
            j %= n;
            b[i] = {p[i][step - 1], p[j][step - 1]};
            cnt[p[i][step - 1]]++;
            v[p[j][step - 1]].p_b(i);
        }

        for(int i = 1; i < n; i++){
            cnt[i] += cnt[i - 1];
        }

        for(int i = n - 1; i >= 0; i--){
            for(auto j : v[i]){
                pos[--cnt[p[j][step - 1]]] = j;
            }
            v[i].clear();
        }

        stn = 0;

        for(int i = 0; i < n; i++){
            if(!stn || last != b[pos[i]]){
                stn++;
                p[pos[i]][step] = stn - 1;
                last = b[pos[i]];
            }else p[pos[i]][step] = stn - 1;
        }

    }
}

int POZ[MAXN];

bool cmp(int a, int b){
    return (p[a][19] < p[b][19]);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;
    cin >> s;
    s = s + '#';
    vector <int> pref(n + 1);
    map < int, vector <pair<int, bool> > > mp;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1];

        if(s[i - 1] == '(')pref[i]++;
        else pref[i]--;

        mp[pref[i]].p_b({i - 1, 0});
        mp[pref[i - 1]].p_b({i - 1, 1});
    }

    build_suffix_array();

    for(int i = 0; i < n; i++)POZ[i] = i;
    sort(POZ, POZ + n, cmp);

    for(int i = 0; i < n - 1; i++){
        int res = 0;
        for(int j = 19; j >= 0; j--)if(max(POZ[i + 1], POZ[i]) + pw(j) + res <= n && p[POZ[i] + res][j] == p[POZ[i + 1] + res][j]){
            res |= pw(j);
        }
        LCP[POZ[i + 1]] = res;
    }

    set <int> st;
    set <int> :: iterator it;

    ll ans = 0;

    for(auto i : mp){
        vector < pair<int, bool> > b = i.se;
        vector <int> t;
        for(auto j : b)if(j.se == 0)t.p_b(j.fi);
        for(auto j : b)if(s[j.fi] == '(' && j.se == 1){
            int i = j.fi;
            int uk = n;
            if(!st.empty()){
                it = st.upper_bound(i);
                if(it != st.end()){
                    uk = *it;
                }
            }
            if(uk > i + LCP[i] && sz(t)){
                ans += lower_bound(all(t), uk) - t.begin();
                ans -= lower_bound(all(t), i + LCP[i]) - t.begin();
            }
        }
        for(auto i : b)if(!i.se)st.insert(i.fi);
    }

    cout << ans << "\n";

    return 0;
}