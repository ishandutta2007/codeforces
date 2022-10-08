#include <iostream>
#include <vector>

using namespace std;

const char s[] = "ACTG";

int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        a[i] = c - 'A';
    }

    int ans = 52;
    for (int i = 0; i + 3 < n; ++i)
    {
        int cur = 0;
        for (int j = 0; j < 4; ++j)
        {
            int sj = s[j] - 'A';
            cur += std::min((sj + 26 - a[i + j]) % 26, (a[i + j] + 26 - sj) % 26);
        }
        ans = std::min(ans, cur);
    }

    cout << ans << endl;

    return 0;
}