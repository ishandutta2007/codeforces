#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

//#define int li

int base;

li d[11][70][70];

void precalc() {
    for (int base = 2; base <= 10; base++) {
        for (int place = 0; place <= 69; place++)
            for (int n_odd = 0; n_odd <= base; n_odd++) {
                    if (place == 0) {
                        d[base][place][n_odd] = (n_odd == 0);
                    }
                    else {
                        d[base][place][n_odd] =
                            // place odd
                            (n_odd ? d[base][place - 1][n_odd - 1] * n_odd : 0) +
                            // place even
                            (n_odd + 1 <= base ? d[base][place - 1][n_odd + 1] * (base - n_odd) : 0);
                    }
                }
    }
}

vector<int> digits(li x, int base) {
    vector<int> d;
    while (x) {
        d.push_back(x % base);
        x /= base;
    }
    reverse(all(d));
    return d;
}

// cnt good strictly less than x
li f(li x, int base) {
    vector<int> digs = digits(x, base);
    
    li answer = 0;
    
    int n = digs.size();
    vector<int> cnt(base);
    for (int i = 0; i < n; i++) {
        int n_odd = 0;
        for (int i = 0; i < base; i++) if (cnt[i] % 2 == 1) n_odd++;
        
        // first differing digit
        for (int digit = (i == 0 ? 1 : 0); digit < digs[i]; digit++) {
            int now_odd = (cnt[digit] % 2 == 0 ? n_odd + 1 : n_odd - 1);
            
            answer += d[base][n - i - 1][now_odd];
        }
        
        cnt[digs[i]]++;
    }
    
    for (int len = 1; len < n; len++) {
        answer += (base - 1) * d[base][len - 1][1];
    }
    
    return answer;
}

void solve(bool read) {
    int base;
    li L, R;
    cin >> base >> L >> R;
 
    cout << f(R + 1, base) - f(L, base) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    precalc();
    
#if 0
    for (int base = 2; base <= 10; base++) {
        for (int x = 1; x <= 10000; x++) {
            bool special = (f(x + 1, base) != f(x, base));
            //printf("%d\n", x);
            auto d = digits(x, base);
            vector<int> cnt(base);
            string s;
            for (int y: d) {
                cnt[y]++;
                s += to_string(y);
            }
            bool exp = true;
            for (int y: cnt)
                if (y % 2 == 1)
                    exp = false;
            
            if (special != exp) {
                printf("num %d in base %d (%s): special %d, expected %d\n", x, base, s.c_str(), special ? 1 : 0, exp ? 1 : 0);
            }
            assert(special == exp);
        }
    }
#endif
    
    int nt = 1;
    cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
#if 0
    while (true) {
        guessed = false;
        solve(false);
        assert(guessed);
    }
#endif
    
    return 0;
}