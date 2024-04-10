#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005;

char B[NMAX];
int A[NMAX];
int ans[NMAX];

char fans[NMAX];

bool solve(int left, int right) {
    if (left > right) return false;
    int l = left, r = right;
    for (int i = 1; i <= right; ++i) {
        A[i] = B[i] - '0';
    }
    memset(ans, 0, sizeof ans);

    if (A[left - 1] > 1) return false;

    int cl = A[left - 1], cr = 0;
    while (left <= right) {
        int sum = (A[right] - cr + 10) % 10;
        if (cr) {
            A[right] = (A[right] + 9) % 10;
        }
        int ncl = A[left] != A[right];
        
        if (ncl && (A[right] + 1) % 10 != A[left]) {
            return false;
        }
        if (ncl && cl) {
            if (A[left] == 0) {
                ans[left] = 4;
                ans[right] = 5;
            } else {
                ans[left] = (A[left] + 10) / 2;
                ans[right] = A[left] + 10 - ans[left] - 1;
            }
        } else if (!ncl && cl) {
            if (A[left] == 9) {
                return false;
            } else {
                ans[left] = (A[left] + 10 + 1) / 2;
                ans[right] = A[left] + 10 - ans[left];
            }
        } else if (ncl && !cl) {
            if (A[left] == 0) {
                return false;
            } else {
                ans[left] = A[left] / 2;
                ans[right] = A[left] - ans[left] - 1;
            }
        } else {
            ans[left] = (A[left] + 1) / 2;
            ans[right] = A[left] - ans[left];
        }

        cl = ncl;
        cr = ans[left] + ans[right] + cr >= 10;

        left++;
        right--;
    }

    for (int i = 1; i <= r; ++i) {
        A[i] = B[i] - '0';
    }
    
    cr = 0;
    for (int i = r; i >= 1; --i) {
        int sum = ans[i] + ans[r + l - i] + cr;
        if (sum % 10 != A[i]) return false;
        cr = sum >= 10;
    }
    if (ans[l] == 0) return false;

    for (int i = l; i <= r; ++i) {
        fans[i - l] = ans[i] + '0';
    }
    return true;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    cin >> B + 1;
    int n = strlen(B + 1);

    if (solve(1, n) || solve(2, n)) {
        cout << fans << '\n';
    } else {
        cout << "0\n";
    }
}