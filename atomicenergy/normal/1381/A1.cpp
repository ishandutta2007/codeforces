#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p;
        string a, b;
        cin >> a >> b;
        for (int i = n-1; i >=0; i--) {
            if (((n - i) % 2) == 0) {
                if (a[n - (n - i) / 2] != b[i]) p.push_back(1);
                p.push_back(i + 1);
            }
            else {
                if (a[(n - 1 - i) / 2] == b[i]) p.push_back(1);
                p.push_back(i + 1);
            }
        }
        cout << p.size() << " ";
        for (int i = 0; i < p.size(); i++) {
            cout << p[i];
            if (i + 1 < p.size()) cout << " ";
        }
        cout << endl;
    }

}