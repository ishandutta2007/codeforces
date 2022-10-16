#include <iostream>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cout << "YES\n";
    for (int i = 1; i <= n; ++ i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int parX = (x1 % 2 + 10) % 2;
        int parY = (y1 % 2 + 10) % 2;

        parX *= 2;

        int col = parX + parY + 1;
        cout << col << '\n';
    }

    return 0;
}