#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

const int N = 1e5;

bool used[N];

int main() {
    int n, m;
    cin >> n >> m;
    int cnt, t;
    fr(i, n) {
        cin >> cnt;
        fr(j, cnt) {
            cin >> t;
            used[t - 1] = true;
        }
    }
    if (accumulate(used, used + m, 0) == m)
        cout << "YES";
    else
        cout << "NO";
}