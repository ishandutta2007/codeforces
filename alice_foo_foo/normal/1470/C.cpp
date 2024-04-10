#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

int n, k;

int query(int x) {
    x = (x - 1) % n + 1;
    cout << "? " << x << endl;
    int ans; cin >> ans; return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    if (n <= 300) {
        for (int i = 1; i <= 150; i++) query(1);
        if (n & 1) {
            int pos = 0;
            for (int i = 1; i <= n; i++) {
                int res = query(i);
                if (res != k) continue;
                res = query(i);
                if (res != k) continue;
                pos = i;
                break;
            }
            if (!pos) {
                int angry = 0;
                while (1) {
                    ++angry;
                }
            }
            cout << "! " << pos << endl;
        } else {
            int pos = 0;
            for (int i = 1; i <= n; i++) {
                int res = query(i);
                if (res == k) {
                    pos = i;
                    break;
                }
            }
            if (!pos) {
                int angry = 0;
                while (1) {
                    ++angry;
                }
            }
            int pos2 = (pos + n / 2 - 1) % n + 1;
            int nxt1 = pos % n + 1, nxt2 = pos2 % n + 1;
            int val1 = query(nxt1), val2 = query(nxt2);
            if (val1 > val2) cout << "! " << pos << endl;
            else cout << "! " << pos2 << endl;
        }
    } else {
        query(1);
        int l = 1, r = 0, round = 2;
        while (1) {
            l = r + 1; r = l + round * 2;
            if (query(l + round - 1) != k) break;
            if (query(l + round) != k) break;
            round += 2;
        }
        // for (int i = l; i <= r; i++) {
        //     if (query(i) == k) {
        //         cout << "! " << (i - 1) % n + 1 << endl;
        //         break;
        //     }
        // }
        // int cando = 0;
        // for (int i = l + round; i <= r; i++) {
        //     if (query(i) == k) {
        //         cout << "! " << (i - 1) % n + 1 << endl;
        //         cando = 1;
        //         break;
        //     }
        // }
        // if (!cando) {
        //     for (int i = l + round - 1; i >= l; i--) {
        //         if (query(i) == k) {
        //             cout << "! " << (i - 1) % n + 1 << endl;
        //             cando = 1;
        //             break;
        //         }
        //     }
        // }
        int ans = r;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (query(mid) >= k) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << "! " << (ans - 1) % n + 1 << endl;
    }
    return 0;
}