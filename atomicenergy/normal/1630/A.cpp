

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

        if (n == 4 && k == 3) {
            cout << -1 << endl;
                continue;
        }

        int prev = n - 1;

        set<int> pows;
        set<int> seen;
        for (int j = 1; j < n; j *= 2) {
            if (k & j) {
                cout << j << " " << prev << endl;
                seen.insert(prev);
                seen.insert(j);

                prev = n-1-j;
            }
        }

        cout << 0 << " " << prev << endl;
        seen.insert(prev);
        seen.insert(0);


        for (int i = 0; i < n; i++) {
            if (seen.count(i)) continue;

            else {
                cout << i << " " << n-1-i << endl;
                seen.insert(i);
                seen.insert(n-1-i);
            }

        }

    }
}