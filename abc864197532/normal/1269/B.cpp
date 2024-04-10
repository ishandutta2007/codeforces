#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

int main () {
    int n,m;
    cin >> n >> m;
    int a[n], b[n];
    fop (i,0,n) cin >> a[i];
    fop (i,0,n) cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    int minn = INT_MAX;
    fop (i,0,n) {
        bool is = true;
        int aa = a[0] - b[i];
        fop (j,1,n) {
            if (a[j] - b[(i + j) % n] != aa and a[j] - b[(i + j) % n] + m != aa and a[j] - b[(i + j) % n] - m != aa) {
                is = false;
                break;
            }
        }
        if (is) {
            aa = -aa;
            if (aa < 0) aa += m;
            minn = min(minn, aa);
        }
    }
    cout << minn << endl;
}