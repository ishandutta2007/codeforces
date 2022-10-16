#include <iostream>

using namespace std;

const int NMAX = 10000 + 5;

int N;
int v[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];

    while (M --) {
        int l, r, x;
        cin >> l >> r >> x;

        int cnt = 0;
        for (int i = l; i <= r; ++ i)
            if (v[i] < v[x])
                ++ cnt;

        if (cnt != x - l)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}