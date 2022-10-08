#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, s;
    vector<int> smaller, larger;

    cin >> n >> s;

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        if (tmp < s)
        {
            smaller.push_back(s - tmp);
        }
        else if (tmp > s)
        {
            larger.push_back(tmp - s);
        }
    }

    long long ans = 0;
    if (smaller.size() > n / 2)
    {
        sort(smaller.begin(), smaller.end());
        for (int i = 0; i + n / 2 < smaller.size(); ++i)
        {
            ans += smaller[i];
        }
    }
    if (larger.size() > n / 2)
    {
        sort(larger.begin(), larger.end());
        for (int i = 0; i + n / 2 < larger.size(); ++i)
        {
            ans += larger[i];
        }
    }
    cout << ans << endl;

    return 0;
}