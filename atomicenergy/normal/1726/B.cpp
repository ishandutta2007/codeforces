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
        long long n, m;
        cin >> n >> m;
        if (n % 2 == 1) {
            if (m < n) {
                cout << "No" << endl;
            }
            else {
                cout << "Yes" << endl;
                for (int i = 1; i < n; i++) cout << 1 << " ";
                cout << m - (n - 1) << endl;
            }
        }
        else {
            if (m < n || (m%2 == 1)) {
                cout << "No" << endl;
            }
            else {
                cout << "Yes" << endl;
                for (int i = 1; i < n-1; i++) cout << 1 << " ";
                cout << (m - (n - 2))/2 << " " << (m - (n - 2)) / 2 << endl;
            }
        }
    }
}