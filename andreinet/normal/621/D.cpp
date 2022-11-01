#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
typedef long double ldouble;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    string q = "xyz";
    int ord[] = {0, 1, 2};
    ldouble A[3];
    cin >> A[0] >> A[1] >> A[2];

    ldouble mx = -1e99;
    string ans = "";
    do {
        ldouble cval, x, y, z;

        //cerr << ord[0] << ' ' << ord[1] << ' ' << ord[2] << endl;
        //cerr << q << endl;

        x = A[ord[0]], y = A[ord[1]], z = A[ord[2]];
        cval = pow(y, z) * log(x);
        if (cval > mx + 1e-10) {
            mx = cval;
            ans = string() + q[0] + "^" + q[1] + "^" + q[2];
        }

        swap(q[1], q[2]);
        swap(ord[1], ord[2]);

        x = A[ord[0]], y = A[ord[1]], z = A[ord[2]];
        cval = pow(y, z) * log(x);
        if (cval > mx + 1e-10) {
            mx = cval;
            ans = string() + q[0] + "^" + q[1] + "^" + q[2];
        }
        
        swap(q[1], q[2]);
        swap(ord[1], ord[2]);

        x = A[ord[0]], y = A[ord[1]], z = A[ord[2]];
        cval = y * z * log(x);
        if (cval > mx + 1e-10) {
            mx = cval;
            ans = string() + "(" + q[0] + "^" + q[1] + ")^" + q[2];
        }

        swap(q[1], q[2]);
        swap(ord[1], ord[2]);

        x = A[ord[0]], y = A[ord[1]], z = A[ord[2]];
        cval = y * z * log(x);
        if (cval > mx + 1e-10) {
            mx = cval;
            ans = string() + "(" + q[0] + "^" + q[1] + ")^" + q[2];
        }
        next_permutation(q.begin(), q.end());
    } while(next_permutation(ord, ord + 3));

    cout << ans << '\n';
}