
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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<pair<int, int> > locs;
    vector<pair<int, int>> ones;
    vector<pair<int, int> > opens;
    vector<pair<int, int> > opensones;
    int col = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == 0) continue;
        if (v[i] == 1) {
            locs.push_back({ i, col });
            opensones.push_back({i, col});
            col--;
        }
        if (v[i] == 2) {
            if (ones.size() == 0 && opensones.size() == 0) {
                cout << -1 << endl;
                return 0;
            }
            pair<int, int> p;
            if (ones.size() != 0) {
                p = ones.back();
                ones.pop_back();
            }
            else {
                p = opensones.back();
                opensones.pop_back();
            }

            locs.push_back({ i, p.second });

            opens.push_back({ i, p.second });
        }
        if (v[i] == 3) {
            if (opens.size() == 0 && opensones.size() == 0) {
                cout << -1 << endl;
                return 0;
            }
            pair<int, int> p;
            if (opens.size() != 0) {
                p = opens.back();
                opens.pop_back();
            }
            else {
                p = opensones.back();
                opensones.pop_back();
            }
            locs.push_back({ i, col });
            locs.push_back({ p.first, col });
            opens.push_back({ i, col });
            
            col--;
            
        }

    }

    cout << locs.size() << endl;
    for (int i = 0; i < locs.size(); i++) {
        cout << locs[i].second + 1 << " " << locs[i].first + 1 << endl;
    }


}