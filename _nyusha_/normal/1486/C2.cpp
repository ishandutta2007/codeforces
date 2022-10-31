#include<bits/stdc++.h>

using namespace std;

map < pair < int, int >, int > ask;

int get(int l, int r) {
    if (ask.find({l, r}) != ask.end()) {
        return ask[{l, r}];
    }
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    ask[{l, r}] = x;
    return x;
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int pos = get(1, n);
    if (pos != 1 && get(1, pos) == pos) {
        int l = 0, r = pos;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (get(m, pos) == pos) l = m;
            else r = m;
        }
        cout << "! " << l << endl;
    }
    else {
        int l = pos, r = n + 1;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (get(pos, m) == pos) r = m;
            else l = m;
        }
        cout << "! " << r << endl;
    }
    return 0;
}