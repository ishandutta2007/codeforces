#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& a, vector<int>& used, int& tot, int i, int n)
{
    if (tot == n)
    {
        return;
    }
    if (i == n)
    {
        for (int j : a)
            cout << j << " ";
        cout << "\n";
        ++tot;
        return;
    }

    for (int j = 0; j < n; ++j)
    {
        if (!used[j] && (i < 2 || j + 1 != a[i - 1] + a[i - 2]))
        {
            a[i] = j + 1;
            used[j] = 1;

            dfs(a, used, tot, i + 1, n);

            used[j] = 0;
        }
    }
}

int main()
{
    int ct;
    cin >> ct;

    for (int t = 0; t < ct; ++t)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> used(n);
        int tot = 0;
        dfs(a, used, tot, 0, n);
    }

    return 0;
}