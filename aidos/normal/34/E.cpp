
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e5 + 10;
int n;
ld T;
ld x[maxn], v[maxn], m[maxn];
ld V[maxn];
ld eps = 1e-12;
ld l[maxn];
ld r[maxn];
int p[maxn];
void solve() {
    cin >> n >> T;
    for(int i = 1; i <= n; i++) {
        double a, b, c;
        cin >> a >> b >> c;
        x[i] = a;
        v[i] = b;
        m[i] = c;
    }
    ld cur = 0;
    while(T > eps) {
        ld cur = T;

        for(int i = 1; i <= n; i++) {
            p[i] = i;
            V[i] = v[i];
            for(int j = i + 1; j <= n; j++) {
                ld A = x[i] - x[j];
                ld B = v[j] - v[i];
                if(abs(B) < eps) continue;
                ld t = A/B;
                if(t < eps) continue;
                cur = min(cur, t);
            }
        }
        for(int i = 1; i <= n; i++) {
            //p[i] = i;
            for(int j = i + 1; j <= n; j++) {
                ld A = x[i] - x[j];
                ld B = v[j] - v[i];
                if(abs(B) < eps) continue;
                ld t = A/B;
                if(t < eps) continue;
                if(t < cur + eps) {
                    V[i] = ((m[i] - m[j]) * v[i] + 2 * m[j] * v[j])/(m[i] + m[j]);
                    V[j] = ((m[j] - m[i]) * v[j] + 2 * m[i] * v[i])/(m[i] + m[j]);
                }
            }
        }
        T -= cur;
        for(int i = 1; i <= n; i++) {
            x[i] = x[i] + v[i] * cur;
            v[i] = V[i];
        }
    }
    cout << setprecision(12);
    for(int i = 1; i <= n; i++) {
        cout <<fixed<< (double)x[i] << "\n";
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}