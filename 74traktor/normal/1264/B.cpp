#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
int a[maxn], cnt[5];

vector < pair < int, int > > Q;

inline void check() {
    int ptr = 2, lst = -1;
    for (auto key : Q) {
        if (cnt[key.first] > 0 && cnt[key.second] > 0) {
            lst = key.first;
            break;
        }
    }
    //cout << "OK" << endl;
    if (lst == -1) return;
    cnt[lst]--;
    a[1] = lst;
    int ok;
    while (cnt[0] + cnt[1] + cnt[2] + cnt[3] > 0) {
        ok = 1;
        for (auto key : Q) {
            if (key.first == lst && cnt[key.second] > 0) {
                a[ptr++] = key.second, lst = key.second;
                ok = 0;
                cnt[key.second]--;
                break;
            }
        }
        if (ok) return;
    }
    cout << "YES" << '\n';
    for (int i = 1; i < ptr; ++i) {
        cout << a[i] << " ";
    }
    exit(0);
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b + c + d == 1) {
        cout << "YES" << '\n';
        if (a) cout << 0;
        else if (b) cout << 1;
        else if (c) cout << 2;
        else cout << 3;
        return 0;
    }
    for (int i = 0; i <= 3; ++i) {
        if (i != 0) Q.push_back({i, i - 1});
        if (i != 3) Q.push_back({i, i + 1});
    }
    for (int i = 1; i <= 720; ++i) {
        cnt[0] = a, cnt[1] = b, cnt[2] = c, cnt[3] = d;
        check();
        if (i != 720) next_permutation(Q.begin(), Q.end());
    }
    cout << "NO" << '\n';
    return 0;
}