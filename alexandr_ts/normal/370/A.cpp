#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

const int N = 1e5;

bool used[N];

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << 2 - (x1 == x2) - (y1 == y2) << " ";
    if (((x1 + y1) % 2) ^ ((x2 + y2) % 2))
        cout << 0;
    else if (x1 - y1 == x2 - y2 || x1 - x2 == y2 - y1)
        cout << 1;
    else
        cout << 2;

    cout << " ";
    cout << max(abs(x1 - x2), abs(y1 - y2));
}