#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const int INF = 2e9 + 1;

int a[N];
int pos[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i + 1];
    frab(i, 1, n + 1)
        pos[a[i]] = i;
    int ans = 0, cur = 0;
    frab(i, 1, n + 1)
        if (pos[i] > pos[i - 1])
            cur++;
        else {
            ans = max(ans, cur);
            cur = 1;
        }
    cout << n - max(ans, cur);
}