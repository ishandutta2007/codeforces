//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

random_device rddev;

mt19937 rd(rddev());

vector<int> cur_;
int n, k;
int ANS;

int randint(int l, int r) {
    int cur = rd() % (r - l + 1);
    cur += (r - l + 1);
    cur %= (r - l + 1);
    return cur + l;
}

void init() {
    n = randint(4, 10);
    k = randint(1, 100) * 2;
    ANS = randint(0, n - 1);
    cur_.clear();
    cur_.assign(n, k);
}

void move() {
    vector<int> cur2;
    cur2.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (i == ANS) {
            cur2[(i + 1) % n] += cur_[i];
        } else {
            cur2[(i + 1) % n] += (cur_[i] + 1) / 2;
            cur2[(i + n - 1) % n] += (cur_[i]) / 2;
        }
    }
    cur_ = cur2;
}

int ask(int x) {
    if (0) {
        int kek = cur_[x];
        move();
        return kek;
    }

    cout << "? " << x + 1 << endl;
    cin >> x;
    return x;
}

int answer(int x) {
    if (0)
        assert(x == ANS);
    cout << "! " << x + 1 << endl;
    exit(0);
}

void solve() {
    cin >> n >> k;
    int sq =  1;
    while ((sq + 1) * (sq + 1) <= n) {
        sq++;
    }
    int cur = 0;
    cur += n;
    cur %= n;
    while (true) {
        int x = ask(cur);
        if (x == k) {
            cur += sq + randint(0, 1);
            cur %= n;
        } else {
            if (x < k) {
                while (x != k) {
                    cur++;
                    cur %= n;
                    x = ask(cur);
                }
                answer(cur);
            } else {
                while (x!= k) {
                    cur += n - 1;
                    cur %= n;
                    x = ask(cur);
                }
                answer(cur);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // coment next line if there is only one test
    //cin >> t;

    while (t--) {
        //init();
        //cout << n << " " << k << " " << ANS + 1 << endl;
        solve();
    }
}