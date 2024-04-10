#include <iostream>

using namespace std;

const int NMAX = 200000 + 5;

int n;
int v[NMAX];

int freq[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int s;
    cin >> n >> s;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    int addent = 0;
    if (v[s] != 0) {
        addent = 1;
        v[s] = 0;
    }

    if (n == 1) {
        cout << addent << '\n';
        return 0;
    }

    for (int i = 1; i <= n; ++ i)
        ++ freq[v[i]];

    int extra = freq[0] - 1;
    for (int i = 1; i < n; ++ i)
        extra += freq[i];

    int ans = n + 1;
    int need = 0;
    for (int h = 1; h < n; ++ h) {
        if (freq[h] == 0)
            ++ need;
        extra -= freq[h];

        int current;
        if (extra >= need)
            current = addent + extra;
        else
            current = addent + need;

        if (current < ans)
            ans = current;
    }

    cout << ans << '\n';
    return 0;
}