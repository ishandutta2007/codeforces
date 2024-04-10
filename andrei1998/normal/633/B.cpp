#include <iostream>
#include <vector>

using namespace std;

int cinci(int n) {
    int ans = 0;
    while (n % 5 == 0)
        n /= 5, ++ ans;

    return ans;
}

vector <int> ans;

int main()
{
    int m = 0;
    cin >> m;

    int _5 = 0;
    for (int i = 1; ; ++ i) {
        _5 += cinci(i);

        if (_5 == m)
            ans.push_back(i);
        else if (_5 > m)
            break;
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++ i)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    return 0;
}