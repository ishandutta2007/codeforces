#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
using namespace std;

char sir[300005];

int main()
{
    ios_base :: sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    cin.get();
    cin.get(sir + 1, 300005);

    int bucati = 0;
    int puncte = 0;

    for (int i = 1; i <= n; i++)
        if (sir[i] == '.') {
            puncte++;
            if (i == 1 || sir[i - 1] != '.')
                bucati ++;
        }
        else
            sir[i] = 'a';

    int x;
    char lit;

    sir[0] = sir[n + 1] = 'a';

    while (m--) {
        cin >> x >> lit;

        if (islower(lit))
            lit = 'a';

        //update la puncte si bucati
        if (sir[x] != lit) {
            if (lit == '.') {
                puncte ++;

                if (sir[x - 1] == sir[x + 1]) {
                    if (sir[x - 1] == 'a')
                        bucati ++;
                    else
                        bucati --;
                }
            }
            else {
                puncte --;

                if (sir[x - 1] == sir[x + 1]) {
                    if (sir[x - 1] == 'a')
                        bucati --;
                    else
                        bucati ++;
                }
            }
        }

        sir[x] = lit;

        cout << puncte - bucati << '\n';
    }

    return 0;
}