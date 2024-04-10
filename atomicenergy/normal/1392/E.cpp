using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <ctime>

typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //srand(time(NULL));

    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            if (i % 2 == 0) cout << 0 << " ";
            else cout << ((ll)1 << (i + j)) << " ";
        }
        cout << endl;
    }
    long long q;
    cin >> q;
    for (long long c = 0; c < q; c++) {
        long long ans;
        cin >> ans;
        long long x = 0;
        long long y = 0;
        while (x+y != 2*n-2) {
            cout << x + 1 << " " << y + 1 << endl;
            if (ans & ((ll)1 << (x + 1 + y))) {
                if (x % 2 == 0) {
                    x++;
                    continue;
                }
                else {
                    y++;
                    continue;
                }
            }
            else {
                if (x % 2 == 0) {
                    y++;
                    continue;
                }
                else {
                    x++;
                    continue;
                }
            }
        }
        cout << n  << " " << n  << endl;
     }


}