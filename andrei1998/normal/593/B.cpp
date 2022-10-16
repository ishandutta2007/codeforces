#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

struct line {
    lint y1, y2;
};

bool operator < (const line &a, const line &b) {
    if (a.y1 != b.y1)
        return a.y1 < b.y1;
    return a.y2 < b.y2;
}

line lines[100005];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    int x1, x2;
    cin >> x1 >> x2;

    int k, b;
    for (int i = 1; i <= n; ++ i) {
        cin >> k >> b;
        lines[i].y1 = 1ll * k * x1 + b;
        lines[i].y2 = 1ll * k * x2 + b;
    }

    sort(lines + 1, lines + n + 1);

    bool sortat = true;
    for (int i = 2; i <= n; ++ i) {
        if (lines[i - 1].y2 > lines[i].y2)
            sortat = false;
    }

    if (sortat == false)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}