#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 100 + 5;

int N, W;

pair <int, int> v[NMAX];
int a[NMAX];

int main()
{
    cin >> N >> W;
    for (int i = 1; i <= N; ++ i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v + 1, v + N + 1);

    for (int i = 1; i <= N; ++ i) {
        a[v[i].second] = (v[i].first + 1) / 2;
        W -= a[v[i].second];
    }

    if (W < 0) {
        cout << "-1\n";
        return 0;
    }

    for (int i = N; i; -- i) {
        while (W && a[v[i].second] < v[i].first) {
            -- W;
            ++ a[v[i].second];
        }
    }

    for (int i = 1; i <= N; ++ i)
        cout << a[i] << " \n"[i == N];
    return 0;
}