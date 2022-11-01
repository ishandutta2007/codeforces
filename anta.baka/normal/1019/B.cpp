#include <bits/stdc++.h>
using namespace std;

int get(int i) {
    cout << "? " << i + 1 << endl;
    int x; cin >> x;
    return x;
}

int main() {
    int n; cin >> n;
    if((n / 2) & 1) return cout << "! -1" << endl, 0;
    int base = get(n / 2) - get(0);
    if(base == 0) return cout << "! 1" << endl, 0;
    int lf = 0, rg = n / 2 - 1;
    while(lf < rg) {
        int md = (lf + rg) >> 1;
        int s = get(md + n / 2) - get(md);
        if(base > 0) {
            if(s > 0) lf = md + 1;
            else rg = md;
        } else {
            if(s < 0) lf = md + 1;
            else rg = md;
        }
    }
    cout << "! " << lf + 1 << endl;
}