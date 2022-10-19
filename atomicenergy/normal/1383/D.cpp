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
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));
    vector<vector<int> > u(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    set<int> r;
    set<int> c;
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < m; j++) {
            if (v[i][j] > mx) mx = v[i][j];
        }
        r.insert(mx);
    }
    for (int j = 0; j < m; j++) {
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (v[i][j] > mx) mx = v[i][j];
        }
        c.insert(mx);
    }
    set<pair<int, int> > none;
    set<pair<int, int> > down;
    set<pair<int, int> > right;
    set<pair<int, int> > downleft;
    set<pair<int, int> > upright;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            none.insert({ i, j });
        }
    }
    for (int i = n * m; i >= 1; i--) {
        if (r.count(i) && c.count(i)) {
            if (none.empty()) {
                cout << -1 << endl;
                goto end;

            }
            auto p = *(none.begin());
            u[p.first][p.second] = i;
            none.erase(p);
            for (int i = 0; i < p.first; i++) {
                right.erase({ -i, p.second });
                upright.insert({ -i, p.second });
            }
            for (int i = p.first + 1; i < n; i++) {
                none.erase({ i, p.second });
                down.insert({ i, -p.second });
            }
            for (int j = 0; j < p.second; j++) {
                down.erase({ p.first, -j });
                downleft.insert({ p.first, -j });
            }
            for (int j = p.second + 1; j < m; j++) {
                none.erase({ p.first, j });
                right.insert({ -p.first, j });
            }
        }
        else if (r.count(i)) {
            if (down.empty()) {
                cout << -1 << endl;
                goto end;

            }
            auto p = *(down.begin());
            u[p.first][-p.second] = i;
            down.erase(p);
            for (int j = 0; j < -p.second; j++) {
                down.erase({ p.first, -j });
                downleft.insert({ p.first, -j });
            }
            for (int j = (-p.second) + 1; j < m; j++) {
                none.erase({ p.first, j });
                right.insert({ -p.first, j });
            }
        }
        else if (c.count(i)) {
            if (right.empty()) {
                cout << -1 << endl;
                goto end;

            }
            auto p = *(right.begin());
            u[-p.first][p.second] = i;
            right.erase(p);
            for (int i = 0; i < -p.first; i++) {
                right.erase({ -i, p.second });
                upright.insert({ -i, p.second });
            }
            for (int i = (-p.first) + 1; i < n; i++) {
                none.erase({ i, p.second });
                down.insert({ i, -p.second });
            }

        }
        else {
            if (downleft.empty() && upright.empty()) {
                cout << -1 << endl;
                goto end;
            }
            if (downleft.empty()) {
                auto p = *(upright.begin());
                u[-p.first][p.second] = i;
                upright.erase(p);
            }
            else {
                auto p = *(downleft.begin());
                u[p.first][-p.second] = i;
                downleft.erase(p);
            }
        }
        
    }
        

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << u[i][j] << " ";
        }
        cout << endl;
    }
        end:
    return 0;

}