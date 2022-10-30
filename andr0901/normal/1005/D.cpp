#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector <int> ans(n + 1);
    ans[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        int m = 0;
        int t = 0;
        for (int j = i; j > 0 && (ans[j - 1] >= ans[i - 1] - 1); j--) {
            t += int(s[j - 1]) - '0';
            int x = 0;
            if (t % 3 == 0)  x = 1;
            if (m < x + ans[j - 1]) m = x + ans[j - 1];
        }
        ans[i] = m;
    }
    cout << ans[n];
    return 0;
}