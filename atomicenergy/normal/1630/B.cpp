

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>


using namespace std;

typedef long long ll;



int main(){
    int tests;
    cin >> tests;
    for (int ii = 0; ii < tests; ii++) {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        vector<int> u = v;
        sort(u.begin(), u.end());
        int x = u[0];
        int y = u[u.size() - 1];
        for (int i = 0; i < n; i++) {
            int j = i + (n + k + 1) / 2 - 1;
            if (j >= n) continue;
            if (u[j] - u[i] < y - x) {
                y = u[j];
                x = u[i];
            }
        }
        cout << x << " " << y << endl;

        int cnt = 0;
        int hgh = 0;
        int prev = 1;
        for (int i = 0; i < n; i++) {
            if (v[i] >= x && v[i] <= y) cnt++;
            else cnt--;

            if (cnt > hgh && cnt < k) {
                hgh = cnt;
                cout << prev << " " << i+1 << endl;
                prev = i + 2;
            }
        }
        cout << prev << " " << n << endl;

    }
}