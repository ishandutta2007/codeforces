
using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;


int n, m;
vector<vector<int> > v;
vector<vector<vector<int> > > g;
vector<vector<vector<int> > > mins;
vector<vector<vector<int> > > maxs;

map<int, int> s;
vector<int> place;

bool checkbipartite(int i, int p) {
    s[i] = p;
    for (auto q : g[i]) {
        if (s.count(q[0])) {
            if (s[q[0]] + p == 3) continue;
            return false;
        }
        if (!checkbipartite(q[0], 3 - p)) return false;
    }
    return true;
}

bool placedfs(int i) {
    for (auto q : g[i]) {
        if (q[1] == 0) continue;
        if (place[q[0]] == -100000) {
            place[q[0]] = place[i] + q[1];
            if(!placedfs(q[0])) return false;
        }
        else {
            if (place[q[0]] != place[i] + q[1]) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    
    cin >> n >> m;
    g = vector < vector<vector<int> > >(n);
    mins = vector < vector<vector<int> > >(n);

    maxs = vector < vector<vector<int> > >(n);

    for (int z = 0; z < m; z++) {
        int i, j, b;
        cin >> i >> j >> b;
        i--, j--;
        v.push_back({ i, j, b });
        g[i].push_back({ j, b });
        g[j].push_back({ i, -b });
        if (b == 0) {
            mins[i].push_back({ j, -1 });
            mins[j].push_back({ i, -1 });
            maxs[i].push_back({ j, 1 });
            maxs[j].push_back({ i, 1 });
        }
        else {
            mins[i].push_back({ j, b });
            mins[j].push_back({ i, -b });
            maxs[i].push_back({ j, b });
            maxs[j].push_back({ i, -b });
        }
    }
    if (!checkbipartite(0, 1)) {
        cout << "NO" << endl;
        return 0;
    }
    place = vector<int>(n, -100000);
    for (int i = 0; i < n; i++) {
        if (place[i] != -100000) continue;
        place[i] = 0;
        if (!placedfs(i)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    int themax[200][200];
    int themin[200][200];
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            themin[i][j] = -200000;
            themax[i][j]  = 200000;
        }
        themin[i][i] = 0;
        themax[i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (auto q : mins[i]) themin[i][q[0]] = q[1];
        for (auto q : maxs[i]) themax[i][q[0]] = q[1];

    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (themin[i][j] < themin[i][k] + themin[k][j]) {
                    themin[i][j] = themin[i][k] + themin[k][j];
                }
                if (themax[i][j] > themax[i][k] + themax[k][j]) {
                    themax[i][j] = themax[i][k] + themax[k][j];
                }
                //themax is smallest path from max numbers
                //the min is smallest path from min numbers
            }
        }
    }
    int best = 0;
    int besti = 0;
    int bestj = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (themin[i][j] > themax[i][j]) {
                cout << "NO" << endl;
                return 0;
            }
            if (themax[i][j] > best) {
                best = themax[i][j];
                besti = i;
                bestj = j;
            }
        }
    }
    cout << "YES" << endl;
    cout << best << endl;
    for (int i = 0; i < n; i++) {
        cout << themax[besti][i] << " ";
    }
    cout << endl;

}