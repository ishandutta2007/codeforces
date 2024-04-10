#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
using namespace std;

const int N = 2e6;
const int MAXSZ = 112;
typedef pair <int, int> pr;

int a[N];

bool used[N];
vector <int> prm;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    if (n == 1 && k == 0) {
        cout << 1;
        return 0;
    }
    if (n == 1) {
        cout << -1;
        return 0;
    }
    if (k < n / 2) {
        cout << -1;
        return 0;
    }
    prm.reserve(200000);
    used[0] = used[1] = true;
    frab(i, 2, N)
        if (!used[i])
            for (int j = i * 2; j < N; j += i)
                used[j] = true;
    fr(i, N)
        if (!used[i])
            prm.pb(i);
    prm.resize(n);
    prm[0] *= (1 + (k - n / 2));
    prm[1] *= (1 + (k - n / 2));
    //sort(prm.begin(), prm.end());
    fr(i, n)
        cout << prm[i] << " ";
}