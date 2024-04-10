#include <iostream>

#define lint long long int
using namespace std;

const int NMAX = 200000 + 5;

int n;
int freq[NMAX];

int s_part[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;

    int val;
    for (int i = 1; i <= n; ++ i) {
        cin >> val;
        ++ freq[val];
    }

    for (int i = 1; i <= NMAX - 5; ++ i)
        s_part[i] = s_part[i - 1] + freq[i];

    lint ans = 0;
    for (int lead = 1; lead <= NMAX - 5; ++ lead)
        if (freq[lead]) {
            lint aux = 0;
            for (int j = 2 * lead; (j - lead) <= NMAX - 5; j += lead)
                aux += 1LL * (j - lead) * (s_part[min(j - 1, NMAX - 5)] - s_part[j - lead - 1]);
            if (aux > ans)
                ans = aux;
        }

    cout << ans << '\n';
    return 0;
}