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
        int x, y;
        cin >> n >> x >> y;
        y -= x;
        vector<int> v(n);
        vector<int> u(n, -1);
        map<int, vector<int> > m;
        set < pair<int, pair<int, vector<int> > > > s;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            m[v[i]].push_back(i);
        }
        int z = 1;
        while (m.count(z)) z++;
        for (auto p : m) {
            s.insert({ (int) p.second.size(), {p.first, p.second} });
        }
        for (int i = 0; i < x; i++) {
            auto p = *s.rbegin();
            s.erase(p);
            u[p.second.second.back()] = p.second.first;
            p.second.second.pop_back();
            if(p.first > 1) s.insert({ p.first - 1, p.second });
        }
        int mx = 0;
        vector<int> l;
        for (auto p : s) {
            if (p.first > mx) mx = p.first;
            for (auto i : p.second.second) {
                l.push_back(i);
            }
        }
        
            if (2 * ((n-x) - mx) < y) {
                cout << "NO" << endl;
                continue;
            }
        
        for (int i = 0; i < n - x; i++) {
            if (y>0 && v[l[i]] != v[l[(i + ((n - x) / 2)) % (n - x)]]) {
                u[l[i]] = v[l[(i + ((n - x) / 2)) % (n - x)]];
                y--;
            }
            else {
                u[l[i]] = z;
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << u[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
           
    }

}