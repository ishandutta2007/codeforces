#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        long long best = v[n - 1] - v[0];


        for (int i = 0; i < n; i++) {
            if (i != 0 && v[i] - v[0] > best) best = v[i] - v[0];
            if (i != n - 1 && v[n - 1] - v[i] > best) best = v[n - 1] - v[i];
            if (i != 0 && v[i - 1] - v[i] > best) best = v[i - 1] - v[i];
        }
        cout << best << endl;
    }
}