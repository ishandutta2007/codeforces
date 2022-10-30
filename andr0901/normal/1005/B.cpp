#include <iostream>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size() / 2; i++) swap(a[i], a[a.size() - i - 1]);
    for (int i = 0; i < b.size() / 2; i++) swap(b[i], b[b.size() - i - 1]);
    if (a.size() < b.size()) swap(a, b);
    for (int i = 0; i < b.size(); i++) {
        if (a[i] != b[i]) {
            cout << a.size() - i + b.size() - i;
            return 0;
        }
    }
    cout << a.size() - b.size();
    return 0;
}