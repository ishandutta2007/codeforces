#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int xrand() { return abs((rand() << 16) + rand()); }

int add(int a, int b) {
    a += b;
    while (a > 1e6) a -= 1e6;
    return a;
}

void solve(bool) {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> b;
    
    set<int> sums;
    for (int iter = 0; iter < n; iter++) {
        while (true) {
            int num = xrand() % (int)1e6 + 1;
            
            bool fail = false;
            for (int x: a)
                if (sums.count(add(x, num))) {
                    fail = true;
                    break;
                }
                
            if (fail) continue;
                    
            for (int x: a)
                sums.insert(add(x, num));
            b.push_back(num);
            break;
        }
    }
    
    cout << "YES\n";
    for (int x: b) { cout << x << " "; assert(x >= 1 && x <= (int)1e6); } cout << "\n"; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt;
    cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    return 0;
}