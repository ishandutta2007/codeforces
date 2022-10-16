#include <iostream>
#include <cstring>

#define lint long long int
using namespace std;

const int NMAX = 1000005;
char sir[NMAX];
char aux[NMAX];

lint dp1[NMAX];
lint dp2[NMAX];

int n = 0, a, b;
lint T;

lint best() {
    memset(aux, 0, sizeof aux);
    memset(dp1, 0, sizeof dp1);
    memset(dp2, 0, sizeof dp2);

    lint ans = 0;

    dp1[1] = b * (sir[1] == 'w') + 1;
    if (dp1[1] <= T)
        ans = 1;
    else
        return 0;
    for (int i = 2; i <= n; ++ i) {
        dp1[i] = dp1[i - 1] + a + (sir[i] == 'w') * b + 1;
        if (dp1[i] <= T)
            ans = i;
    }

    //Consideram ca deja plecam cu costul bun din n
    dp2[n] = b * (sir[n] == 'w') + 1;
    for (int i = n - 1; i >= 1; -- i)
        dp2[i] = dp2[i + 1] + a + (sir[i] == 'w') * b + 1;


    //Incercam sa fixam un i
    lint t;
    int iter = 2;
    for (int i = 1; i < n; ++ i) {
        t = T - dp1[i] - i * a;
        if (t <= 0)
            break;

        while (iter <= i || dp2[iter] > t)
            ++ iter;

        if (iter <= n) {
            if (n - iter + 1 + i > ans)
                ans = n - iter + 1 + i;
        }
    }

    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin >> n >> a >> b >> T;

    cin.get();
    cin.get(sir + 1, NMAX);

    int ans = best();

    aux[1] = sir[1];
    int pos = 1;
    for (int i = n; i > 1; -- i)
        aux[++ pos] = sir[i];

    for (int i = 1; i <= n; ++ i)
        sir[i] = aux[i];

    int auxx = best();
    if (auxx > ans)
        ans = auxx;

    cout << ans << '\n';
    return 0;
}