#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const int INF = 2 * 1e9 + 1;
const ld EPS = 1e-9;

struct tmp {
    int x, n;
};

bool cmp(tmp a, tmp b) {
    return a.x < b.x;
}

bool cmp2(tmp a, tmp b) {
    return a.n < b.n;
}

tmp a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    string s;
    cin >> n;
    cin >> s;
    int q1 = 0, q0 = 0;
    fr(i, n)
        if (s[i] == '0')
            q0++;
        else
            q1++;
    cout << abs(q0 - q1);


}