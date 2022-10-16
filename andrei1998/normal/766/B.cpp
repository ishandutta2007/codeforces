#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 100000 + 5;

int N;
int v[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];
    sort(v + 1, v + N + 1);

    for (int i = 1; i + 2 <= N; ++ i)
        if (v[i] + v[i + 1] > v[i + 2]) {
            cout << "YES\n";
            return 0;
        }

    cout << "NO\n";
    return 0;
}