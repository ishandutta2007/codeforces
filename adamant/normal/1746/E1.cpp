#include <bits/stdc++.h>

using namespace std;

#define int int64_t

vector<int> cons_bit(int n, int k) {
    vector<int> res;
    for(int i = 1; i <= n; i++) {
        if((i >> k) & 1) {
            res.push_back(i);
        }
    }
    return res;
}

bool ask(vector<int> t) {
    if(t.empty()) {
        return false;
    }
    cout << "? ";
    cout << t.size() << ' ';
    for(auto it: t) {
        cout << it << ' ';
    }
    cout << endl;
    string ans;
    cin >> ans;
    return ans == "YES";
}

void solve() {
    int n;
    cin >> n;
    int bits = 0;
    vector<int> cons[2];
    while((1 << bits) <= n) {
        bits++;
    }
    for(int i = 1; i < bits; i++) {
        bool A = ask(cons_bit(n, i));
        bool B = ask(cons_bit(n, 0));
        bool C = ask(cons_bit(n, 0));
        bool D = ask(cons_bit(n, i));
        if(A) {
            cons[!B].push_back(i);
        }
        if(D) {
            cons[!C].push_back(i);
        }
    }
    for(int z = 0; z < 2; z++) {
        int cand = z;
        for(auto it: cons[z]) {
            cand += 1 << it;
        }
        if(1 <= cand && cand <= n) {
            cout << "! " << cand << endl;
            string ans;
            cin >> ans;
            if(ans == ":)") {
                return;
            }
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    cerr << clock() / double(CLOCKS_PER_SEC) << endl;
    //return 0;
}