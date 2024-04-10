#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int main () {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    pii A[1001];
    fop (i,0,1001) A[i] = mp(-1, -1);
    vector <int> is(1000001, false);
    fop (i,1,1001) is[i * i] = true;
    fop (i,1,1001) {
        fop (j,i+1,1001) {
            if (i * i + j * j <= 1000000 and is[i * i + j * j]) {
                int k = sqrt(i * i + j * j);
                A[k] = mp(i, j);
            }
        }
    }
    if (A[g].X == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n0 0\n";
    cout << A[g].X * a << ' ' << -A[g].Y * a << '\n' << A[g].Y * b << ' ' << A[g].X * b << '\n';
}