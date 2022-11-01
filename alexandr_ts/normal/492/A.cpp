#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;

int a[N];
vector <int> g[N];
bool used[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll n;
    cin >> n;
    ll cur = 0, step = 1;
    while (cur <= n) {
        if (cur + step * (step + 1) / 2 <= n) {
            cur += step * (step + 1) / 2;
            step++;
        }
        else
            break;
    }
    cout << step - 1 << endl;
}