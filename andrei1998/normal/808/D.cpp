#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int NMAX = 100000 + 5;
typedef long long int lint;

int N;
int a[NMAX];

set <lint> Set;

lint sPart[NMAX];
bool solve() {
    for (int i = 1; i <= N; ++ i)
        sPart[i] = a[i] + sPart[i - 1];

    //No move
    for (int i = 1; i < N; ++ i)
        if (sPart[i] == sPart[N] - sPart[i])
            return true;

    //Move left to right
    Set.clear();
    for (int i = 1; i <= N; ++ i) {
        Set.insert(a[i]);
        if (i > 1) {
            lint aux = 2 * sPart[i] - sPart[N];
            if (aux % 2 == 0) {
                aux /= 2;
                if (Set.count(aux))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> a[i];

    bool ans = solve();
    reverse(a + 1, a + N + 1);
    ans |= solve();

    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}