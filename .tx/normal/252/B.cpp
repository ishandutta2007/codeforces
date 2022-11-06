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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(31);

    scid(n);
    int diff = -1;
    vector<int> a(n);
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        if (i && a[i] != a[i - 1]) {
            diff = i;
        }
        m[a[i]].push_back(i);
    }


    if (diff == -1) {
        cout << -1;
        return 0;
    }

    vector<int> s = a;
    sort(s.begin(), s.end());
    vector<int> rs(s.rbegin(), s.rend());
    vector<int> ds;
    for (auto& i : m) {
        ds.push_back(i.first);
    }

    if (n > 100) {
        while (true) {
            int num1 = ds[rand() % ds.size()];
            int num2 = ds[rand() % ds.size()];

            if (num1 == num2) {
                continue;
            }

            int x1 = m[num1][rand() % m[num1].size()];
            int x2 = m[num2][rand() % m[num2].size()];

            swap(a[x1], a[x2]);

            if (a == s || a == rs) {
                swap(a[x1], a[x2]);
                continue;
            }

            cout << x1 + 1 << " " << x2 + 1;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] != a[j]) {
                swap(a[i], a[j]);
                if (a != s && a != rs) {
                    cout << i + 1 << " " << j + 1;
                    return 0;
                }
                swap(a[i], a[j]);
            }
        }
    }

    cout << -1;

    return 0;
}