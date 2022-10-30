#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector <int> p;
    for (int i = 0; i < n; i++) {
        cout << m << endl;
        fflush(stdout);
        int ans;
        cin >> ans;
        if (ans == 0 || ans == -2) return 0;
        else if (ans == 1) p.push_back(1);
        else p.push_back(0);
    }
    int l = 1, r = m;
    int i = 0;
    while (r != l) {
        int mid = (l + r) / 2;
        cout << mid << endl;
        fflush(stdout);
        int ans;
        cin >> ans;
        if (ans == 0 || ans == -2) return 0;
        if (p[i % n] == 0) {
            if (ans == 1) l = mid;
            else r = mid;
        }
        else {
            if (ans == 1) r = mid;
            else l = mid;
        }
        i++;
    }
    cout << l << endl;
    fflush(stdout);
    return 0;
}