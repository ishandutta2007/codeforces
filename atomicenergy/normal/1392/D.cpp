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

    long long tests;
    cin >> tests;
    for (long long casenum = 1; casenum <= tests; casenum++) {
        long long n;
        cin >> n;

        string s;
        cin >> s;
        bool alll = true;
        bool allr = true;
        long long cr = 0;
        vector<long long> all;
        for (long long i = 0; i < s.size(); i++) {
            if (i == 0) {
                cr++;
                continue;
            }
            if (s[i] == s[i - 1]) {
                cr++;
                continue;
            }
            all.push_back(cr);
            cr = 1;
        }
        all.push_back(cr);
        if (all.size() % 2 == 1 && all.size() > 1) {
            all[0] += all.back();
            all.pop_back();
        }
        if (all.size() == 1) {
            if (all[0] < 3) {
                cout << 0 << endl;
                continue;
            }
            cout << (all[0] + 2) / 3 << endl;
            continue;
        }
        long long ans = 0;
        for (auto i : all) {
            ans += i / 3;
        }
        cout << ans << endl;
    }


}