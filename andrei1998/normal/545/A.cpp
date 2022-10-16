#include <iostream>
#include <vector>

using namespace std;

vector <int> ans;

int main()
{
    ios_base :: sync_with_stdio(false);
    int n = 0;
    cin >> n;

    int x, j;
    bool au;

    for (int i = 1; i <= n; i++) {
        au = false;
        for (j = 1; j <= n; j++) {
            cin >> x;

            if (x == 1 || x == 3)
                au = true;
        }

        if (!au)
            ans.push_back(i);
    }

    cout << ans.size() << endl;

    if (ans.size() == 0)
        return 0;

    cout << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ' ' << ans[i];
    cout << endl;

    return 0;
}