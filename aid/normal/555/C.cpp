#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, pair<int, int> > mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    mp[make_pair(0, n)] = make_pair(0, 0);
    for(int i = 0; i < q; i++) {
        int x, y;
        char dir;
        cin >> x >> y >> dir;
        x--;
        y--;
        map<pair<int, int>, pair<int, int> >::iterator it =
            mp.upper_bound(make_pair(x, n));
        if(it == mp.begin()) {
            cout << 0 << '\n';
            continue;
        }
        it--;
        int l = it->first.first, r = it->first.second,
            vu = it->second.first, vl = it->second.second;
        if(!(l <= x && x < r)) {
            cout << 0 << '\n';
            continue;
        }
        mp.erase(it);
        if(dir == 'L') {
            if(x > l)
                mp[make_pair(l, x)] = make_pair(y + 1, vl);
            if(x + 1 < r)
                mp[make_pair(x + 1, r)] = make_pair(vu, vl);
            cout << x + 1 - vl << '\n';
        }
        else {
            if(x > l)
                mp[make_pair(l, x)] = make_pair(vu, vl);
            if(x + 1 < r)
                mp[make_pair(x + 1, r)] = make_pair(vu, x + 1);
            cout << y + 1 - vu << '\n';
        }
    }
    return 0;
}