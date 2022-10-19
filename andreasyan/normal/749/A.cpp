#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> ans;
    while (n)
    {
        if (n == 3)
        {
            ans.push_back(3);
            n -= 3;
        }
        else
        {
            ans.push_back(2);
            n -= 2;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}