#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n * 2; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    if (v[n - 1] == v[n]) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}