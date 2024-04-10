#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int n;
char s[2105];

int m;
char sir[2105];

pair <int, int> get_best(int start) {
    //Direct
    int best = 0;
    pair <int, int> ans(-1, -1);

    for (int i = 1; i <= n; ++ i) {
        int j;
        for (j = i; j <= n && start + j - i <= m; ++ j)
            if (sir[start + j - i] != s[j])
                break;
        -- j;

        if (j - i + 1 > best) {
            best = j - i + 1;
            ans = make_pair(i, j);
        }
    }

    //Invers
    for (int i = 1; i <= n; ++ i) {
        int j;
        for (j = i; j > 0 && start + i - j <= m; -- j)
            if (sir[start + i - j] != s[j])
                break;
        ++ j;

        if (i - j + 1 > best) {
            best = i - j + 1;
            ans = make_pair(i, j);
        }
    }

    return ans;
}

vector <pair <int, int> > ans;

int main()
{
    cin.get(s + 1, 2105);
    n = strlen(s + 1);

    cin.get();
    cin.get(sir + 1, 2105);
    m = strlen(sir + 1);

    for (int start = 1; start <= m; ) {
        pair <int, int> aux = get_best(start);

        if (aux.first == -1) {
            cout << "-1\n";
            return 0;
        }

        ans.push_back(aux);
        start += abs(aux.first - aux.second) + 1;
    }

    cout << ans.size() << '\n';
    for (auto it: ans)
        cout << it.first << ' ' << it.second << '\n';
    return 0;
}