// Created by artsem on 07.06.19.
//

#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


const int M = 200200;

int n;
int a[M], b[M];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int j = 0; j < n; ++j)
        cin >> b[j];
}


void kill() {
    if (*max_element(b, b + n) == 0) {
//        cerr << "null\n";
        cout << n << "\n";
        return;
    }

    if (b[n - 1] > 0) {
        bool ok = true;
        int last = b[n - 1];
        for (int i = 1; i <= last; ++i)
            if (b[n - i] != last - i + 1) {
                ok = false;
            }

        for (int j = 0; j < n - last; ++j)
            if (b[j] > 0 && b[j] <= last + j + 1) {
                ok = false;
            }

//        cerr << "seg\n";

        if (ok) {
            cout << n - last << "\n";
            return;
        }
    }

//    cerr << "simpl\n";
    int ans = n;
    for (int j = 0; j < n; ++j)
        if (b[j] > 0 && b[j] <= j + 1) {
            ans = max(ans, n + j - b[j] + 2);
        }
    cout << ans << "\n";
}

int main() {
//#ifdef LOCAL
//    assert(freopen("f.in", "r", stdin));
//#endif

    ios_base::sync_with_stdio(false);

    read();
    kill();
}