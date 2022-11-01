#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const int M = 20;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

string rev(string s) {
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return s1;
}

vector <pair <string, ll> >a1, a2, pal;

bool cmp(pair <string, ll> a, pair <string, ll> b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    //freopen("a.in", "r", stdin);
    int k, n;
    cin >> k >> n;
    fr(i, k) {
        string s;
        ll ai;
        cin >> s >> ai;
        if (s == rev(s))
            pal.pb(mp(s, ai));
        else if (s < rev(s))
            a1.pb(mp(s, ai));
        else
            a2.pb(mp(rev(s), ai));
    }
    sort(a1.begin(), a1.end(), cmp);
    sort(a2.begin(), a2.end(), cmp);
    sort(pal.begin(), pal.end(), cmp);

    ll ans1 = 0;
    ll cur2 = 0;
    fr(i, a1.size()) {
        //cout << a1[i].first << " " << a1[i].second << endl;
        while (cur2 < a2.size() && a2[cur2].first < a1[i].first)
            cur2++;
        //cout << a2[cur2].first << " " << a2[cur2].second << endl;
        if (cur2 < a2.size() && a2[cur2].first == a1[i].first)
            if (a1[i].second + a2[cur2].second > 0) {
                ans1 += (a1[i].second + a2[cur2].second);
                cur2++;
            }
    }

    ll ans2 = 0;
    ll minneg = 0;
    ll maxpos = 0;
    fr(i, pal.size()) {
        if (i + 1 < pal.size() && pal[i].first == pal[i + 1].first) {
            if (pal[i].second >= 0 && pal[i + 1].second >= 0)
                ans2 += (pal[i].second + pal[i + 1].second);
            else if (pal[i].second + pal[i + 1].second >= 0) {
                ans2 += (pal[i].second + pal[i + 1].second);
                minneg = min(minneg, min(pal[i].second, pal[i + 1].second));
            }
            else {
                maxpos = max(maxpos, pal[i].second);
            }
            i++;
        }
        else
            maxpos = max(maxpos, pal[i].second);
    }
    //cout << ans1 << " " << ans2 << " " << minneg << " " << maxpos << endl;
    cout << ans1 + ans2 + max(maxpos, -minneg);
}