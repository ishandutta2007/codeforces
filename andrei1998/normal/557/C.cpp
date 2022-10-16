#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
using namespace std;

pair <int, int> ob[100005];

priority_queue <int> coada;

int main()
{
    ios_base :: sync_with_stdio(false);
    int sum = 0;

    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> ob[i].first;

    for (int i = 1; i <= n; i++) {
        cin >> ob[i].second;
        sum += ob[i].second;
    }

    sort(ob + 1, ob + n + 1);

    int ans = 0;

    int j;
    for (int i = 1; i <= n; i++) {
        int adunat = 0;
        for (j = i; j <= n; j++)
            if (ob[j].first != ob[i].first)
                break;
            else
                adunat += ob[j].second;
        j --;

        int sz = j - i;

        vector <int> aux;
        while (sz --)
            if (!coada.empty()) {
                adunat += coada.top();
                aux.push_back(coada.top());
                coada.pop();
            }

        for (auto it: aux)
            coada.push(it);

        if (adunat > ans)
            ans = adunat;

        while (i <= j) {
            coada.push(ob[i].second);
            i++;
        }
        aux.clear();

        i = j;
    }

    cout << sum - ans << '\n';
    return 0;
}