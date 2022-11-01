#include <bits/stdc++.h>
using namespace std;

string code(int i, int j) {
    return char(i + 'a') + to_string(j + 1);
}

vector<pair<int, int>> doLine(int start, int end, int line, bool doStart) {

    vector<pair<int, int>> sol;
    
    if(doStart) {
        sol.push_back({line, start});
    }

    for(int i = 0; i < 8; i += 1) {
        if(i != start and i != end) {
            sol.push_back({line, i});
        }
    }
    
    sol.push_back({line, end});
    return sol;
}

vector<pair<int, int>> cut(vector<pair<int, int>> sol, int required) {
	while(int(sol.size()) > required + 1) {
        bool found = false;
        int who = -1;

        for(int i = 1; i < int(sol.size()) - 1; i += 1) {
            if(sol[i - 1].first == sol[i + 1].first or sol[i - 1].second == sol[i + 1].second) {
                found = true;
                who = i;
                break;
            }
        }
        
        if(found) {
            sol.erase(sol.begin() + who);
        } else {
            break;
        }
    }

    if(int(sol.size()) == required + 1)
        return sol;
    return vector<pair<int, int>> ();
}

int main() {
    int n; cin >> n;

    vector<int> ends;

    ends.push_back(2);
    ends.push_back(1);
    
    for(int i = 2; i < 8; i += 1) {
        ends.push_back(i);
    }
    
    vector<pair<int, int>> sol;

    for(int i = 0; i < 8; i += 1) {
        bool doStart = true;
        int start = 0;
        if(i > 0)
            start = ends[i - 1];
        vector<pair<int, int>> here = doLine(start, ends[i], i, doStart);
        for(auto cell : here)
            sol.push_back(cell);
    }
    
    sol = cut(sol, n);

    if(sol.empty()) {
        for(int j = 0; j < 8; j += 1) {
            sol.push_back({0, j});
        }
        for(int j = 1; j < 8; j += 1) {
            sol.push_back({j, 7});
        }
        sol = cut(sol, n);
    }

    for(auto cell : sol)
        cout << code(cell.first, cell.second) << " ";
}