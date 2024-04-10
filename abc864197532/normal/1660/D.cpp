#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define X first
#define Y second
#define all(x) x.begin(), x.end()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T i, U ...j) {
    cout << i << ' ', abc(j...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l)
        cout << *l << " \n"[l + 1 == r];
}
#ifdef Doludu
#define test(x...) abc("[" + string(#x) + "]", x)
#define owo freopen("input.txt", "r", stdin)
#else
#define test(x...) void(0)
#define owo ios::sync_with_stdio(false), cin.tie(0)
#endif
const int N = 200000;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int ansl = 0, ansr = n, anscnt = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            while (i < n && a[i] == 0)
                i++;
            j = i;
            if (i == n)
                break;
            while (j < n && a[j] != 0) 
                j++;
            // range [i, j)
            int f = 0, cnt = 0;
            for (int k = i; k < j; ++k) {
                assert(a[k] != 0);
                if (a[k] < 0)
                    f ^= 1;
                if (a[k] == 2 || a[k] == -2)
                    cnt++;
            }
            if (f) {
                // find one negative
                {
                    int p = -1, nowcnt = cnt;
                    for (int k = i; k < j; ++k) {
                        if (a[k] == 2 || a[k] == -2)
                            nowcnt--;
                        if (a[k] < 0) {
                            p = k + 1;
                            break;
                        }
                    }
                    if (anscnt < nowcnt)
                        ansl = p, ansr = n - j, anscnt = nowcnt;
                }
                {
                    int p = -1, nowcnt = cnt;
                    for (int k = j - 1; k >= i; --k) {
                        if (a[k] == 2 || a[k] == -2)
                            nowcnt--;
                        if (a[k] < 0) {
                            p = k;
                            break;
                        }
                    }
                    if (anscnt < nowcnt)
                        ansl = i, ansr = n - p, anscnt = nowcnt;
                }
            } else {
                if (anscnt < cnt)
                    ansl = i, ansr = n - j, anscnt = cnt;
            }
        }
        cout << ansl << ' ' << ansr << '\n';
    }
}