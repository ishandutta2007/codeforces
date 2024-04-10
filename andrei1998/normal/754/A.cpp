#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int v[105];
vector <pair <int, int> > ans;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    int j;
    for (int i = 1; i <= n; i = j) {
        int sum = 0;
        j = i;
        while (j <= n && (sum == 0 || v[j] == 0)) {
            sum += v[j];
            ++ j;
        }

        if (sum == 0) {
            cout << "NO\n";
            return 0;
        }

        ans.push_back(make_pair(i, j - 1));
    }

    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto it: ans)
        cout << it.first << ' ' << it.second << '\n';
    return 0;
}