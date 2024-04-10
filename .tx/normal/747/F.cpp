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
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int k, t;

int ct[11];

int get_id(int rest) {
    int res = 0;
    for (int i = 1; i <= t; i++) {
        res = (res << 3) + ct[i];
    }
    res = (res << 4) + rest;
    return res;
}

unordered_map<int, lint> d;

lint cnt(int rest) {
    if (rest == 0) {
        return 1;
    }
    int id = get_id(rest);
    if (d.find(id) != d.end()) {
        return d[id];
    }
    lint res = 0;
    for (int i = 0; i < t; i++) {
        if (ct[i] > 0) {
            ct[i]--;
            ct[i + 1]++;
            lint r = cnt(rest - 1);
            ct[i + 1]--;
            ct[i]++;
            res += r * ct[i];
        }    
    }
    d[id] = res;
    return res;
}

int ans[22];
int ca[22];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    sci(k, t);
    if (t >= 8 || k <= 15) {
        printf("%x", k);
        return 0;
    }
    
    ct[0] = 16;
    
    int len = 1;
    for (;; len++) {
        lint x = cnt(len);
        if (len != 1) {
            if (x % 16 != 0) {
                cout << ":(" << endl;
            }
            x = x / 16 * 15;
        }
        if (x > k) {
            break;
        }
        k -= x;
    }
    
    for (int i = 0; i < len; i++) {
        for (int c = (i == 0 ? 1 : 0); c <= 15; c++) {
            if (ca[c] == t) {
                continue;
            }
            ct[ca[c]]--;
            ct[ca[c] + 1]++;
            lint x = cnt(len - i - 1);
            if (x > k) {
                ca[c]++;
                ans[i] = c;
                break;
            }
            k -= x;
            ct[ca[c] + 1]--;
            ct[ca[c]]++;
        }    
    }
    
    for (int i = 0; i < len; i++) {
        if (ans[i] < 10) {
            cout << char(ans[i] + '0');
        } else {
            cout << char(ans[i] - 10 + 'a');
        }
    }

    return 0;
}