
using namespace std;

//#define fileio

#ifndef fileio
#include <iostream>
#endif
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

typedef long long ll;

#ifdef fileio
ifstream cin;
ofstream cout;
#endif



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef fileio
    cin.open("Text.txt");
    cout.open("Output.txt");
#endif
    int n;
    int m;

    cin >> n >> m;

    vector<vector<int> > g;
    g = vector<vector<int> >(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back({ x, i });
    }

    vector<int>  u(n, -1);

    
    sort(v.begin(), v.end());
    for (auto p : v) {
        set<int> s;
        for (auto q : g[p.second]) {
            s.insert(u[q]);
        }
        int z = 1;
        while (s.count(z)) z++;
        if (p.first != z) {
            cout << -1 << endl;
            return 0;
        }
        else u[p.second] = p.first;
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].second+1 << " ";
    }
    cout << endl;



}