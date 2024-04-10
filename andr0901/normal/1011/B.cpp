#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> a(101);
    for (int i = 0; i < 101; i++) a[i] = 0;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        a[t]++;
    }
    int d = 1;
    int p = 0;

    while (1) {
        for (int i = 0; i < a.size(); i++) {
            p += a[i] / d;
            if (p >= n) {
                d++;
                p = 0;
                goto asdf;
            }
        }
        cout << d - 1;
        return 0;
        asdf: {}
    }
    return 0;
}