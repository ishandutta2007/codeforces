#include <bits/stdc++.h>

using namespace std;

//#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target("avx2")


#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
const ll int_max = 1e9 + 7;

ll n, i, j, sum;
vector<vector<ll>> m;
vector<ll> v, s;
unordered_set<int> have;
unordered_map<int, int> mp;
vector<vector<int>> masks;
vector<vector<pll>> var;
vector<vector<pll>> vec;

vector<ll> how;
vector<bool> can;
bool viv = false;

void bad() {
    cout << "No" << endl;
    exit(0);
}

void add(vector<ll> who, vector<ll> vals) {
    if (viv) {
        cout << "Add " << endl;
        for (auto i : who)
            cout << i << ' ';
        cout << endl;
        for (auto i : vals)
            cout << i << ' ';
        cout << endl;
    }

    vector<pll> lvar;
    for (ll i = 0; i < who.size(); i++)
        lvar.push_back({who[i], vals[i]});
    var.push_back(lvar);
}

bool is_int(ll val) {
    if (val > int_max || val < -int_max)
        return false;
    return true;
}

void solve(ll val, ll pl) {
    ll cval = val;
    ll cpl = pl;
    set <ll> st;
    st.insert(pl);
    vector<ll> who, whopl;
    set<ll> used;
    who.push_back(cval);
    whopl.push_back(cpl);
    used.insert(cpl);
    if (viv)
        cout << "Start with " << cval << ' ' << cpl << endl;
    while (true) {
        ll nval = cval + v[cpl];
        if (!is_int(nval))
            return;
        ll npl = mp[nval];
        if (viv)
            cout << "Go to with " << nval << ' ' << npl << endl;
        if (!is_int(nval) || have.count(nval) == 0)
            return;
        if (npl == pl && nval == val) {
            add(whopl, who);
            return;
        }
        if (used.count(npl))
            return;
        used.insert(npl);
        who.push_back(nval);
        whopl.push_back(npl);
        cval = nval;
        cpl = npl;
    }
}

void prepare() {
    can.resize((1<<n));
    can[0] = true;
    how.resize((1<<n));
    vec.resize(1<<n);
    for (auto v : var) {
        ll mask = 0;
        for (auto p : v)
            mask |= (1 << p.F);
        if (vec[mask].empty())
            vec[mask] = v;
    }
}

vector<ll> gg(vector<ll> a) {
    vector<ll> res;
    for (ll i = 0; i < (1 << a.size()); i++) {
        ll g = i;
        ll cnt = 0;
        sum = 0;
        ll mask = 0;
        while (g) {
            if (g & 1)
                mask |= (1 << a[cnt]), sum++;
            cnt++;
            g >>= 1;
        }
        if (2*sum <= a.size() || sum == a.size())
            res.push_back(mask);
    }
    return res;
}

void check(ll mask) {
    if (viv)
        cout << "Check for " << mask << endl;
    ll wmask = mask;
    vector<ll> a;
    ll cnt = 0;
    while (wmask) {
        if (wmask&1)
            a.push_back(cnt);
        cnt++;
        wmask >>= 1;
    }
//    vector<ll> smask = gg(mask);
/**    int hb = a.back();
    int omask = mask ^ (1 << hb);
    vector<int> smask = masks[omask];
    int sz = smask.size();
    for (ll i = 0; i < sz; i++)
        smask.push_back(smask[i] ^ (1 << hb));
    masks[mask] = smask;
**/
    vector<ll> smask(1, 0);
    for (ll s = mask; s > 0; s = ((s-1) & mask))
        smask.push_back(s);

    for (auto s : smask)
        if (vec[s].size() && can[mask^s]) {
            can[mask] = true;
            how[mask] = s;
        }
}

int main() {
//    viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    m.resize(n);
    s.resize(n);
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        for (ll j = 0; j < a; j++) {
            ll x;
            cin >> x;
            m[i].push_back(x);
            s[i] += x;
            sum += x;
            have.insert(x);
            mp[x] = i;
        }
    }
    if (sum % n)
        bad();
    sum /= n;
    for (ll i = 0; i < n; i++) {
        v.push_back(sum - s[i]);
    }

    for (ll i = 0; i < n; i++)
        for (auto j : m[i])
            solve(j, i);

    prepare();
    masks.resize(1 << n);
    masks[0] = {0};
    for (ll i = 1; i < (1 << n); i++)
        check(i);

    if (viv) {
        cout << "Masks\n";
        for (auto i : can)
            cout << i;
        cout << endl;
    }
    if (!can.back())
        bad();


    cout << "Yes\n";
    ll now = can.size() - 1;
    if (viv)
        cout << now << endl;

    vector<ll> vall(n, 0);
    vector<ll> wheree(n, 0);

    while (now != 0) {
        ll mask = how[now];
        if (viv)
            cout << "Use " << mask << endl;
        auto v = vec[mask];
        if (viv) {
            for (auto i : v)
                cout << i.F << ' ' << i.S << "; ";
            cout << endl;
        }
        for (ll i = 0; i < v.size(); i++) {
            wheree[v[(i + 1 + v.size())%v.size()].F] = v[(i)].F;
            vall  [v[(i - 0 + v.size())%v.size()].F] = v[(i)].S;
        }
        now ^= mask;
    }

    for (ll i = 0; i < n; i++) {
        cout << vall[i] << ' ';
        cout << wheree[i] + 1 << ' ';
        cout << endl;
    }



    return 0;
}