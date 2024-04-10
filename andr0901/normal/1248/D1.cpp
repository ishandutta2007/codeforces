#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
class Min_Stack {
private:
    vector <int> vals, mins;
public:
    void push_back(int x) {
        if (mins.empty())
            mins.pb(x);
        else
            mins.pb(min(mins.back(), x));
        vals.pb(x);
    }

    void pop_back() {
        vals.pop_back();
        mins.pop_back();
    }

    int back() const {
        return vals.back();
    }

    int get() const {
        if (mins.empty())
            return 1e4;
        return mins.back();
    }

    bool empty() const {
        return mins.empty();
    }
};

class Min_Queue {
private:
    Min_Stack a, b;
public:
    void push_back(int x) {
        b.push_back(x);
    }

    void pop_front() {
        if (a.empty()) {
            while (!b.empty()) {
                a.push_back(b.back());
                b.pop_back();
            }
        }
        a.pop_back();
    }

    int get() const {
        return min(a.get(), b.get());
    }
};

int n;
vector <int> pref;

void upd(int i, int x) {
    forn (j, i, i + n)
        pref[j] += x;
    forn (j, i + n, 2 * n)
        pref[j] += 2 * x;
}

main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    pref.resize(2 * n);
    vector <int> b(n);
    forn (i, 0, n) {
        char c;
        cin >> c;
        if (c == '(')
            b[i] = 1;
        else
            b[i] = -1;
        upd(i, b[i]);
    }
    bool calculated = false;
    int ans = 0;
    pii ans_idx;
    forn (i, 0, n) {
        forn (j, i, n) {
            if (b[i] == b[j] && calculated)
                continue;
            int v = b[i], u = b[j];
            upd(i, (u - v)), upd(j, (v - u));
            int cnt = 0;
            Min_Queue q;
            forn (k, 0, n)
                q.push_back(pref[k]);
            forn (k, 0, n) {
                if (pref[k] == pref[k + n] && q.get() == pref[k])
                    cnt++;
                q.pop_front();
                if (k != n - 1)
                    q.push_back(pref[k + n]);
            }
            if (cnt > ans) {
                ans = cnt;
                ans_idx = {i, j};
            }
           upd(i, -(u - v)), upd(j, -(v - u));
           if (b[i] == b[j])
                calculated = true;
        }
    }
    cout << ans << "\n";
    cout << ans_idx.fs + 1 << " " << ans_idx.sc + 1;
    return 0;
}