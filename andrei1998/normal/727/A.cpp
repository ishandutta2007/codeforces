#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;

bool do_transform(int a, int b) {
    v.push_back(b);
    if (a == b)
        return true;
    if (b < a)
        return false;

    if (b % 2 == 0)
        return do_transform(a, b >> 1);
    else if (b % 10 == 1)
        return do_transform(a, (b - 1) / 10);
    else
        return false;
}

int main()
{
    int a, b;
    cin >> a >> b;

    if (do_transform(a, b)) {
        cout << "YES\n";
        reverse(v.begin(), v.end());
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); ++ i)
            cout << v[i] << " \n"[i + 1 == v.size()];
    }
    else {
        cout << "NO\n";
    }

    return 0;
}