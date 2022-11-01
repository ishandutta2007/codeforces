#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>

using namespace std;

const int NMAX = 100000 + 5;
const long double EPS = 1E-10;

int N, H, K;
pair <pair <int, int>, int> v[NMAX];

int sol[NMAX];

bool solve(long double t) {
    int cnt = 0;
    for (int i = 1; i <= N && cnt < K; ++ i)
        if ((cnt + 1.0L) * H <= t * v[i].first.second + EPS)
            sol[++ cnt] = v[i].second;

    return cnt == K;
}

int main()
{
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> H;
    for (int i = 1; i <= N; ++ i)
        v[i].second = i;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i].first.first;
    for (int i = 1; i <= N; ++ i)
        cin >> v[i].first.second;
    sort(v + 1, v + N + 1);

    long double st = 0;
    long double dr = 1.5E9;

    for (int steps = 1; steps <= 100; ++ steps) {
        long double mid = (st + dr) * 0.5;
        if (!solve(mid))
            st = mid;
        else
            dr = mid;
    }

    solve(dr);
    for (int i = 1; i <= K; ++ i)
        cout << sol[i] << " \n"[i == N];
    return 0;
}