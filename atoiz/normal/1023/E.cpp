#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ask(int x1, int y1, int x2, int y2)
{
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    string str;
    cin >> str;
    return str == "YES";
}

signed main()
{
    int n;
    cin >> n;
    int r1 = 1, c1 = 1, r2 = n, c2 = n;
    char ans[2*n-2];

    for (int i = 0; i < n-1; ++i) {
        if (ask(r1 + 1, c1, n, n)) {
			ans[i] = 'D';
            ++r1;
        } else {
            ans[i] = 'R';
			++c1;
        }
    }

    for (int i = 2*n-3; i >= n-1; --i) {
        if (ask(1, 1, r2, c2 - 1)) {
			ans[i] = 'R';
			--c2;
        } else {
            ans[i] = 'D';
            --r2;
        }
    }

    cout << "! ";
    for (int i = 0; i < 2*n-2; ++i) cout << ans[i];
    cout << endl;
}