#include <bits/stdc++.h>
using namespace std;

int nbVotes[101][101];
int sommes[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nbCandidats, nbStations;
    cin >> nbCandidats >> nbStations;

    for(int iStation = 0;iStation < nbStations;iStation++) {
        for(int iCandidat = 0;iCandidat < nbCandidats;iCandidat++) {
            cin >> nbVotes[iStation][iCandidat];
            sommes[iCandidat] += nbVotes[iStation][iCandidat];
        }
    }

    vector<int> bests;
    for(int st = 0;st < nbStations;st++)
        bests.push_back(st);

    for(int c = 0;c < nbCandidats - 1;c++) {
        vector<pair<int, int>> diffs;

        for(int st = 0;st < nbStations;st++) {
            diffs.push_back({nbVotes[st][c] - nbVotes[st][nbCandidats - 1], st});
        }
        sort(diffs.begin(), diffs.end());

        int d = sommes[nbCandidats - 1] - sommes[c];

        vector<int> sol;

        int i = 0;
        while(d > 0) {
            d += diffs[i].first;
            sol.push_back(diffs[i].second);
            i++;
        }

        if(sol.size() < bests.size())
            bests = sol;
    }

    cout << bests.size() << "\n";
    for(int v : bests) {
        cout << v + 1 << " ";
    }
    cout << "\n";

    return 0;
}