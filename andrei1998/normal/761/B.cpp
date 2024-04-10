#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, l;
vector <int> a;
vector <int> b;

void read(vector <int> &v) {
    v.resize(n);
    for (int i = 0; i < n; ++ i)
        cin >> v[i];
    for (int i = n - 1; i >= 0; -- i)
        v[i] -= v[0];
    v[0] = l - v[n - 1];
    for (int i = n - 2; i > 0; -- i)
        v[i + 1] -= v[i];

}

int main()
{
    cin >> n >> l;

    if (n == 1) {
        cout << "YES\n";
        return 0;
    }

    read(a);
    read(b);

    for (int i = 0; i < 2 * n; ++ i) {
        rotate(a.begin(), a.begin() + 1, a.end());
        if (a == b) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}