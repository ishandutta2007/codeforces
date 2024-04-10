#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
vector<ll> v;
bool viv = false;

const ld PI = 3.1415926535897932384626433;
typedef complex<ld> base;

int rev(int val, int b) {
    int res = 0;
    for (int i = 0; i < b; i++) 
        if (val & (1 << i))
            res |= (1 << (b - 1 - i));
    return res;
}


void fft(vector<base> &a, bool inv = false) {
    int n = a.size();

    int lb = 1;
    while ((1 << lb) < n) 
        lb++;

    for (int i = 0; i < n; i++) {
        int rev_i = rev(i, lb);
        if (i < rev_i)
            swap(a[i], a[rev_i]);
    }

    for (int sz = 2; sz <= n; sz <<= 1) {
        ld angle = 2 * PI / sz;
        if (inv) angle *= -1;
        base w1(cos(angle), sin(angle));
        for (int l = 0; l < n; l += sz) {           
            base w(1);
            for (int i = l; i < l + sz / 2; i++) {
                base a_i = a[i], a_j = a[i + sz / 2];
                a[i] = a_i + w * a_j;
                a[i + sz / 2] = a_i - w * a_j;
                w *= w1;
            }
        }
    }
    if (inv)
        for (auto &i : a)
            i /= n;
}

vector<ll> mul(const vector<ll> &a, const vector<ll> &b) {
    vector<base> ca(a.begin(), a.end()); 
    vector<base> cb(b.begin(), b.end()); 
    int sz = 1;
    while (sz / 2 < max(a.size(), b.size())) 
        sz <<= 1;

    while (ca.size() < sz)
        ca.push_back(0);
    while (cb.size() < sz)
        cb.push_back(0);

    fft(ca);
    fft(cb);
    vector<base> cMul(sz);
    for (int i = 0; i < sz; i++)
        cMul[i] = ca[i] * cb[i];

    fft(cMul, true);

    vector<ll> res(sz);
    for (int i = 0; i < sz; i++)
        res[i] = floor(cMul[i].real() + 0.5);
    while (res.size() > 1 && res.back() == 0)
        res.pop_back();

    return res;
}

void solve() {
    cin >> n;
    string s;
    cin >> s;

    vector<ll> v;
    for (auto i : s)
        v.push_back(i == 'V');
    vector<ll> v2;
    for (auto i : s)
        v2.push_back(i == 'K');
    reverse(v2.begin(), v2.end());
    
    auto v3 = mul(v, v2);
    while (v3.size() < 2 * v.size())
        v3.push_back(0);

    if (viv) {
        cout << "v = ";
        for (auto i : v)
            cout << i << ' ';
        cout << endl;
        cout << "v2 = ";
        for (auto i : v2)
            cout << i << ' ';
        cout << endl;
        cout << "v3 = ";
        for (auto i : v3)
            cout << i << ' ';
        cout << endl;
    }
    vector<bool> nice(n + 1, true);
    nice[0] = false;
    for (int i = 0; i < v3.size(); i++)
        if (v3[i]) {
            int k = i - n + 1;
            k = abs(k);
            if (viv)    
                cout << "bad: " << k << endl;
            if (k <= n)
                nice[k] = false;
        }
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j += i)
            if (!nice[j])
                nice[i] = false;
    }
    set<int> ans;
    for (int i = 1; i < nice.size(); i++)
        if (nice[i])
            ans.insert(i);
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}

int main() {
    // viv = true;
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1; 
    cin >> t;
    while (t--)
        solve();

    return 0;
}