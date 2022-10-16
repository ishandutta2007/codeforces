#include <bits/stdc++.h>

using namespace std;

const int NMAX = 22 + 5;

int N;
pair <int, int> a[NMAX];
int b[NMAX];

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++ i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + N);

    for (int i = 0; i < N; ++ i)
        b[a[i].second] = a[(i + 1) % N].first;

    for (int i = 0; i < N; ++ i)
        cout << b[i] << " \n"[i + 1 == N];
    return 0;
}