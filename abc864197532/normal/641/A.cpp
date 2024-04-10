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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int a[n];
    fop (i,0,n) cin >> a[i];
    set <int> vi;
    int now = 0;
    bool is = true;
    while (true) {
        if (vi.count(now)) {
            is = false;
            break;
        }
        vi.insert(now);
        if (s[now] == '<') now -= a[now];
        else now += a[now];
        if (now < 0 or now > n) break;
    }
    if (!is) cout << "IN";
    cout << "FINITE" << endl;
}