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
        string s, t;
        cin >> n;
        cin >> s >> t;
        set<pair<char, char> > v;
        bool ok = true;
        for (int i = 0; i < n; i++) {
           
            if (s[i] > t[i]) ok = false;
            if (s[i] < t[i])  v.insert({ s[i], t[i] });
        }
        if (!ok) {
            cout << -1 << endl;
            continue;
        }
        int tot = 0;
        while (!v.empty()) {
            tot++;
            auto p = *(v.begin());
            v.erase(p);
            while (!v.empty() && (*(v.begin())).first == p.first) {
                auto q = (*(v.begin()));
                v.erase(q);
                v.insert({ p.second, q.second });
            }
        }
        cout << tot << endl;
    }

}