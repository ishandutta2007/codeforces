#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int a[111111];

vector<vector<int> > ps;
bool tt[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);

    for (int i = 0; i < n; i++) {
        sci(a[i]);
        --a[i];
    }

    bool bb = false;

    for (int i = 0; i < n; i++) {
        if (tt[i]) {
            continue;
        }
        if (a[i] == i) {
            cout << "YES\n";
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    cout << j + 1 << " " << i + 1 << "\n";
                }
            }
            return 0;
        }
        vector<int> cv;
        int c = i;
        do {
            tt[c] = true;
            cv.push_back(c);
            c = a[c];
        } while (c != i);
        if (cv.size() & 1) {
            bb = true;
        }
        ps.push_back(cv);
    }

    sort(ps.begin(), ps.end(), [] (const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
    });

    if (bb || ps[0].size() != 2) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for (int i = 1; i < ps.size(); i++) {
        auto& v = ps[i];
        for (int j = 0; j < v.size(); j++) {
            cout << ps[0][j & 1] + 1 << " " << ps[i][j] + 1 << "\n";
        }
    }

    cout << ps[0][0] + 1 << " " << ps[0][1] + 1;


    return 0;
}