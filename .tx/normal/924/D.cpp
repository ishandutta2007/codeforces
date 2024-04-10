#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
#define sz(a) (int)a.size()

ll n, w;
ll x[100007];
ll v[100007];

bool eq1(int s1, int s2){
    ll g1 = x[s1] * (v[s2] + w);
    ll g2 = x[s2] * (v[s1] + w);
    return g1 == g2;
}

bool eq2(int s1, int s2){
    ll g1 = x[s1] * (v[s2] - w);
    ll g2 = x[s2] * (v[s1] - w);
    return g1 == g2;
}

bool cmp1(int s1, int s2){
    ll g1 = x[s1] * (v[s2] + w);
    ll g2 = x[s2] * (v[s1] + w);
    int ff = 0;
    if (v[s1] + w < 0) ff ^= 1;
    if (v[s2] + w < 0) ff ^= 1;
    //cout << g1 << ' ' << g2 << ' ' << x[s1] / (db)(v[s1] + w) << ' ' << x[s2] / (db)(v[s2] + w) << endl;
    return (g1 < g2) ^ ff;
}

bool cmp2(int s1, int s2){
    ll g1 = x[s1] * (v[s2] - w);
    ll g2 = x[s2] * (v[s1] - w);
    int ff = 0;
    if (v[s1] - w < 0) ff ^= 1;
    if (v[s2] - w < 0) ff ^= 1;
    return (g1 < g2) ^ ff;
}

int d[2][100007];

struct fen{
    int t[100007];

    void up(int v){
        for (; v < 100007; v = v | (v + 1)) t[v]++;
    }

    int get2(int v){
        int ans = 0;
        for (; v >= 0; v = (v & (v + 1)) - 1) ans += t[v];
        return ans;
    }

    int get(int l, int r){
        return get2(r) - get2(l - 1);
    }
} t;

bool cmp3(int s1, int s2){
    return mp(d[0][s1], -d[1][s1]) < mp(d[0][s2], -d[1][s2]);
}

bool cmp4(int s1, int s2){
    return mp(-d[0][s1], d[1][s1]) < mp(-d[0][s2], d[1][s2]);
}

ll ans = 0;

template <typename Iter, typename Cmp>
void hsort(Iter begin, Iter end, Cmp cmp) {
    std::make_heap(begin, end, cmp);
    std::sort_heap(begin, end, cmp);
};

int main(){
    // freopen("input.txt", "r", stdin);
    //  freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> x[i] >> v[i];

    vector<int> t1, t2;
    for (int i = 0; i < n; i++) t1.pb(i), t2.pb(i);
    hsort(all(t1), cmp1);
    hsort(all(t2), cmp2);

    int i = 0;
    int dd = 0;
    while(1){
        if (i == t1.size()) break;
        int j = i;
        while(j + 1 < t1.size() && eq1(t1[i], t1[j + 1])) j++;
        for (int s = i; s <= j; s++) d[0][t1[s]] = dd;
        dd++;
        i = j + 1;
    }
    i = 0;
    dd = 0;
    while(1){
        if (i == t2.size()) break;
        int j = i;
        while(j + 1 < t2.size() && eq2(t2[i], t2[j + 1])) j++;
        for (int s = i; s <= j; s++) d[1][t2[s]] = dd;
        dd++;
        i = j + 1;
    }

    //for (int i = 0; i < n; i++) cout << d[0][i] << ' ' << d[1][i] << endl;
    //exit(0);

    vector<int> f;
    for (int i = 0; i < n; i++) f.pb(i);
    hsort(all(f), cmp3);

    for (int i = 0; i < f.size(); i++){
        ans += t.get(d[1][f[i]], 100006);
        t.up(d[1][f[i]]);
    }

    for (int i = 0; i < 100007; i++) t.t[i] = 0;

    hsort(all(f), cmp4);

    for (int i = 0; i < f.size(); i++){
        ans += t.get(0, d[1][f[i]]);
        t.up(d[1][f[i]]);
    }

    cout << ans / 2;

    return 0;
}