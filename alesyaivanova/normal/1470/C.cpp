#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

int n, k;

int ask(int i) {
    cout << "? " << i + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

void go_left(int i) {
    while (true) {
        i = (i - 1 + n) % n;
        int y = ask(i);
        if (y == k) {
            cout << "! " << i + 1 << endl;
            return;
        }
    }
}

void go_right(int i) {
    while (true) {
        i = (i + 1) % n;
        int y = ask(i);
        if (y == k) {
            cout << "! " << i + 1 << endl;
            return;
        }
    }
}

signed main() {
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(0));
    cin >> n >> k;
    int t = sqrt(n) - 1;
    for (int i = 0; i < t; i++) {
        int e = rand() % n;
        int y = ask(e);
        if (y > k) {
            go_left(e);
            return 0;
        }
        if (y < k) {
            go_right(e);
            return 0;
        }
    }
    for (int e = rand() % n; ; e = (e + t) % n) {
        int y = ask(e);
        if (y > k) {
            go_left(e);
            return 0;
        }
        if (y < k) {
            go_right(e);
            return 0;
        }
    }
}