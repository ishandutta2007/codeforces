#include <iostream>
#include <algorithm>
#include <iomanip>

#define lint long long int
using namespace std;

int v[2005];
lint frecv[10005];
lint frecv2[10005];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];
    sort(v + 1, v + n + 1);

    for (int i = 1; i <= n; ++ i)
        for (int j = i + 1; j <= n; ++ j)
            frecv[v[j] - v[i]] ++;

    for (int i = 0; i < 5005; ++ i)
        if (frecv[i])
            for (int j = 0; j < 5005; ++ j)
                if (frecv[j])
                    frecv2[i + j] += 1ll * frecv[i] * frecv[j];

    lint favor = 0;
    lint pos = n * (n - 1ll) / 2;

    pos *= (pos * pos);

    lint sum = 0;
    for (int i = 1; i < 5005; ++ i) {
        favor += sum * frecv[i];
        sum += frecv2[i];
    }

    cout << fixed << setprecision(10) << (1.0 * favor) / pos << '\n';
    return 0;
}