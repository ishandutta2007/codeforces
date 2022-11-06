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

lint get_num(string& a, int l, int r) {
    lint res = 0;
    for (int i = l; i < r; i++) {
        if (a[i] != '.') {
            res = res * 10 + a[i] - '0';
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    lint sum = 0;
    scids(a);
    int n = a.size();
    int l = 0;
    int r = 0;
    while (true) {
        l = r;
        while (l < n && a[l] >= 'a' && a[l] <= 'z') {
            l++;
        }
        r = l;
        while (r < n && !(a[r] >= 'a' && a[r] <= 'z')) {
            r++;
        }
        if (l == n) {
            break;
        }
        lint x = get_num(a, l, r);
        if (r - 3 >= l && a[r - 3] == '.') {

        } else {
            x *= 100;
        }
        sum += x;
    }

    lint f = sum / 100;
    vector<int> d;
    do {
        d.push_back(f % 10);
        f /= 10;
    } while (f > 0);
    reverse(d.begin(), d.end());

    for (int i = 0; i < d.size(); i++) {
        if (i != 0 && (d.size() - i) % 3 == 0) {
            cout << ".";
        }
        cout << d[i];
    }

    if (sum % 100 != 0) {
        cout << ".";
        if (sum % 100 < 10) {
            cout << 0;
        }
        cout << sum % 100;
    }



    return 0;
}