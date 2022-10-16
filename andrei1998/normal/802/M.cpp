#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 2300 + 5;

int N, K;
int v[NMAX];

int main()
{
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i];
    sort(v + 1, v + N + 1);

    int ans = 0;
    for (int i = 1; i <= K; ++ i)
        ans += v[i];
    cout << ans << '\n';
    return 0;
}