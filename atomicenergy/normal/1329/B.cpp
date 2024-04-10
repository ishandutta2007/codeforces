using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int d, m;
        cin >> d >> m;
        long long tot = 1;
        int cur = 1;
        while (true) {
            if (cur > d) break;
            tot *= (min(d - cur + 1, cur)+1);
            cur *= 2;
            tot %= m;
        }
        if (tot == 0) cout << m-1 << endl;
        else cout << tot-1 << endl;
    }

}