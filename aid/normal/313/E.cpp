#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> a, b;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    vector<int> c;
    while(!a.empty()) {
        multiset<int>::const_iterator it = a.end();
        it--;
        multiset<int>::const_iterator x = b.lower_bound(m - *it - 1);
        if(x == b.end())
            x--;
        else
            if(*x != m - *it - 1)
                if(x != b.begin())
                    x--;
                else {
                    x = b.end();
                    x--;
                    multiset<int>::const_iterator y = a.lower_bound(m - *x - 1);
                    if(y != a.begin() || *y == m - *x - 1) {
                        if(*y != m - *x - 1)
                            y--;
                        c.push_back((*x + *y) % m);
                        b.erase(x);
                        a.erase(y);
                        continue;
                    }
                }
        c.push_back((*it + *x) % m);
        a.erase(it);
        b.erase(x);
    }
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    for(int i = 0; i < n; i++)
        cout << c[i] << ' ';
}