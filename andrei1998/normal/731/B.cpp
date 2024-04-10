#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 200000 + 5;
int v[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    for (int i = 1; i <= n; ++ i) {
        v[i] %= 2;
        if (v[i] == 1) {
            if (v[i + 1] == 0) {
                cout << "NO\n";
                return 0;
            }
            else
                v[i + 1] --;
        }
    }

    cout << "YES\n";
    return 0;
}