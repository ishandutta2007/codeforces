#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define endline "\n"

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 12e3 + 12;
const ll INF = 1e15 + 10;

int main() {
    int a, b, c, d, e;
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c >> d >> e;
        int t = (a + c - 1) / c;
        int q = (b + d - 1) / d;
        if (t + q > e)
            cout << "-1\n";
        else 
            cout << t << " " << q << endl;
    }
}