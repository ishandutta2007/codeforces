#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, n) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;

const ll N = 1e5;

int x[N], y[N];

int main() {
    int n;
    cin >> n;
    fr(i, n)
        cin >> x[i] >> y[i];
    if ((*max_element(x, x + n) - *min_element(x, x + n)) * (*max_element(y, y + n) - *min_element(y, y + n)))
        cout << (*max_element(x, x + n) - *min_element(x, x + n)) * (*max_element(y, y + n) - *min_element(y, y + n));
    else
        cout << -1;
}