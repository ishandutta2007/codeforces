#include <bits/stdc++.h>
#define fr(i, n) for (int = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ld EPS = 1e-10;
const int INF = 2e9 + 1;

bool isprime(int n) {
    frab(i, 2, sqrt(n) + 1)
        if (n % i == 0 && i < n)
            return false;
    return true;
}

int main() {
    //freopen ("manyangle.in", "r", stdin);
    int cnt = 0;
    frab(i, 2, 50)
        if (isprime(i)) {
            cout << i << endl;
            string s;
            cin >> s;
            if (s == "yes")
                cnt++;
            if (i * i < 100) {
                cout << i * i << endl;
                cin >> s;
                if (s == "yes")
                    cnt++;
            }
        }
    if (cnt >= 2)
        cout << "composite";
    else
        cout << "prime";
}