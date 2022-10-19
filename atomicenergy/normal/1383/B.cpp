#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>

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
        vector<int> v;
        int i = 1;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            
            tot ^= x;
            v.push_back(x);
        }
        if (tot == 0) {
            cout << "DRAW" << endl;
            continue;
        }
        while (tot>= 2 * i) i *= 2;
        int fs = 0;
        int ts = 0;
        for (auto x : v) {
            if (x & i) ts++;
            else fs++;
        }
        if ((ts % 4) == 3 && (fs % 2) == 0) cout << "LOSE" << endl;
        else cout << "WIN" << endl;

    }

}