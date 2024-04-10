#include <bits/stdc++.h>

using namespace std;

void divs(int g, set<int>& as) {
    for(int i = 1; i * i <= g; i++) {
        if(g % i == 0) {
            as.insert(i);
            if(g / i != i) as.insert(g / i);
        }
    }
}

void solve() {
    int w, l; cin >> w >> l;
    set<int> as;
    as.insert(2);

    divs(__gcd(w - 2, l), as);
    divs(__gcd(w - 1, l - 1), as);
    divs(__gcd(w, l - 2), as);

    cout << as.size() << " ";
    for(auto e : as) cout << e << " ";
    cout << endl;
}

int main()
{
    int t; cin >> t;
    while(t--) solve();
    return 0;
}