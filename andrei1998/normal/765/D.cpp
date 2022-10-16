#include <iostream>

using namespace std;

const int NMAX = 100000 + 5;

int N, M;
int f[NMAX];
int g[NMAX];
int h[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> f[i];

    for (int i = 1; i <= N; ++ i)
        if (f[i] != f[f[i]]) {
            cout << "-1\n";
            return 0;
        }
        else {
            if (!g[f[i]]) {
                g[f[i]] = ++ M;
                h[M] = f[i];
            }
            g[i] = g[f[i]];
        }

    cout << M << '\n';
    for (int i = 1; i <= N; ++ i)
        cout << g[i] << " \n"[i == N];
    for (int i = 1; i <= M; ++ i)
        cout << h[i] << " \n"[i == N];
    return 0;
}