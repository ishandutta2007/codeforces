#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e3 + 1;
const ld EPS = 1e-8;

ll a[N];
vector <ll> ans[N];
ll used[N];

bool cmp1(pair <ll, ll> a, pair <ll, ll> b) {
    return a.first > b.first;
}

bool cmp2(pair <ll, ll> a, pair <ll, ll> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    ll n, k;
    map <ll, ll> mb, ms;
    char c;
    ll t1, t2;
    cin >> n >> k;
    fr(i, n) {
        cin >> c >> t1 >> t2;
        if (c == 'B') mb[t1] += t2;
        else ms[t1] += t2;
    }
    vector <pair <ll, ll> > as, ab;
    for (auto it = mb.begin(); it != mb.end(); it++)
        ab.pb(mp(it->first, it->second));
    for (auto it = ms.begin(); it != ms.end(); it++)
        as.pb(mp(it->first, it->second));
    sort(ab.begin(), ab.end(), cmp1);
    sort(as.begin(), as.end(), cmp2);
    vector <pair <ll, ll> > ansb, anss;
    fr(i, min((ll)as.size(), k))
        anss.pb(as[i]);
    sort(anss.begin(), anss.end());
    fr(i, min((ll)ab.size(), k))
        ansb.pb(ab[i]);
    sort(ansb.begin(), ansb.end());
    reverse(anss.begin(), anss.end());
    reverse(ansb.begin(), ansb.end());
    fr(i, anss.size())
        cout << "S " << anss[i].first << " " << anss[i].second << endl;
    fr(i, ansb.size())
        cout << "B " << ansb[i].first << " " << ansb[i].second << endl;
}