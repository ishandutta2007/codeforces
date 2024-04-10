#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    vector <int> v = {a, b, c};
    sort(v.begin(), v.end());

    cout << v[2] - v[0] << '\n';
    return 0;
}