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

bool clash[10][10][10][10];
bool valid[10][10];
ll thek;

int validAssignments(vector<int> v) {
    if (v.size() == thek) {
        //for (auto i : v) cout << i << " ";
        //cout << endl;
        return 1;
    }
    int tot = 0;
    int curi = v.size();
    for (int curj = 0; curj <= curi; curj++) {
        if (!valid[curi][curj]) continue;
        vector<int> cp = v;
        bool cont = false;
        for (int other = 0; other < curi; other++) {
            if (clash[other][v[other]][curi][curj]) cont = true;;
        }
        if (cont) continue;
        cp.push_back(curj);
        tot += validAssignments(cp);
    }
    return tot;
}

int main() {
    int n, m;
    cin >> n >> m >> thek;

    vector<vector<pair<int, int>> > g(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({ w, y, });
    }
    vector<vector<vector<bool>>> v;

   
    

    for (int i = 0; i < thek; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < thek; k++) {
                for (int l = 0; l <= k; l++) {
                    clash[i][j][k][l] = false;
                }
            }
        }
    }

    for (int i = 0; i < thek; i++) {
        //if a vertex has i+1 outgoing edges
        vector<vector<bool> > u;
        for (int j = 0; j <= i; j++) {
            valid[i][j] = true;
            //and we pick the j+1th edge;
            vector<bool> uu(n, false);
            u.push_back(uu);
        }
        v.push_back(u);
    }

    for (int i = 0; i < n; i++) {

        sort(g[i].begin(), g[i].end());
        for (int j = 0; j < g[i].size(); j++) {
            if (v[g[i].size() - 1][j][g[i][j].second]) valid[g[i].size() - 1][j] = false;
            v[g[i].size() - 1] [j] [g[i][j].second] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        vector<pair<int, int> > ps;
        for (int j = 0; j < thek; j++) {
            for (int k = 0; k <= j; k++) {
                if (v[j][k][i]) ps.push_back({ j, k });
            }
        }
        for (int i = 0; i < ps.size(); i++) {
            for (int j = 0; j < ps.size(); j++) {
                clash[ps[i].first][ps[i].second][ps[j].first][ps[j].second] = true;
            }
        }
    }

    cout << validAssignments({}) << endl;


}