#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Event {
    int lig, col, dist;
};

bool operator < (const Event& a, const Event& b) {
    return a.dist > b.dist;
}

vector<string> lignes;

int sl(int a, int b) {
    if(a == -1) return b;
    return min(a, b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int nbLigs, nbCols;
    cin >> nbLigs >> nbCols;

    int p, q;
    cin >> p >> q;

    vector<vector<int>> dists(
        nbLigs,
        vector<int>(nbCols, -1)
    );

    for(int iLig = 0;iLig < nbLigs;iLig++) {
        string ligne;
        cin >> ligne;
        lignes.push_back(ligne);
    }

    priority_queue<Event> events;

    for(int iLig = 0;iLig < nbLigs;iLig++) {
        for(int iCol = 0;iCol < nbCols;iCol++) {
            if(lignes[iLig][iCol] == '.') {
                events.push({iLig, iCol, 0});
            }
        }
    }

    while(!events.empty()) {
        Event cur = events.top();
        events.pop();

        if(dists[cur.lig][cur.col] != -1)
            continue;
        dists[cur.lig][cur.col] = cur.dist;

        if(cur.lig > 0) {
            char car = lignes[cur.lig - 1][cur.col];
            if(car == 'D')
                events.push({cur.lig - 2, cur.col, cur.dist + q});
            if(car == 'R')
                events.push({cur.lig - 1, cur.col - 1, cur.dist + p});
            if(car == 'L')
                events.push({cur.lig - 1, cur.col + 1, cur.dist + p});
        }

        if(cur.col > 0) {
            char car = lignes[cur.lig][cur.col - 1];
            if(car == 'R')
                events.push({cur.lig, cur.col - 2, cur.dist + q});
            if(car == 'U')
                events.push({cur.lig + 1, cur.col - 1, cur.dist + p});
            if(car == 'D')
                events.push({cur.lig - 1, cur.col - 1, cur.dist + p});
        }

        if(cur.lig < nbLigs - 1) {
            char car = lignes[cur.lig + 1][cur.col];
            if(car == 'U')
                events.push({cur.lig + 2, cur.col, cur.dist + q});
            if(car == 'R')
                events.push({cur.lig + 1, cur.col - 1, cur.dist + p});
            if(car == 'L')
                events.push({cur.lig + 1, cur.col + 1, cur.dist + p});
        }

        if(cur.col < nbCols - 1) {
            char car = lignes[cur.lig][cur.col + 1];
            if(car == 'L')
                events.push({cur.lig, cur.col + 2, cur.dist + q});
            if(car == 'U')
                events.push({cur.lig + 1, cur.col + 1, cur.dist + p});
            if(car == 'D')
                events.push({cur.lig - 1, cur.col + 1, cur.dist + p});
        }
    }

    int best = -1;

    for(int iLig = 0;iLig < nbLigs;iLig++) {
        for(int iCol = 0;iCol < nbCols;iCol++) {
            if(dists[iLig][iCol] == -1) continue;

            if(iLig > 0 && dists[iLig - 1][iCol] != -1) best = sl(best, dists[iLig][iCol] + dists[iLig - 1][iCol]);
            if(iCol > 0 && dists[iLig][iCol - 1] != -1) best = sl(best, dists[iLig][iCol] + dists[iLig][iCol - 1]);
            if(iLig < nbLigs - 1 && dists[iLig + 1][iCol] != -1) best = sl(best, dists[iLig][iCol] + dists[iLig + 1][iCol]);
            if(iCol < nbCols - 1 && dists[iLig][iCol + 1] != -1) best = sl(best, dists[iLig][iCol] + dists[iLig][iCol + 1]);
        }
    }

    cout << best << endl;
    return 0;
}