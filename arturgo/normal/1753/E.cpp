#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 2e9;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int nbOps, budget, coutPlus, coutFois;
    cin >> nbOps >> budget >> coutPlus >> coutFois;

    vector<pair<int, int>> ops;
    ops.emplace_back(0, 1);
    for (int i = 0; i < nbOps; ++i) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '*' and x == 1)
            continue;
        ops.emplace_back(c == '*', x);
    }
    nbOps = ops.size();
    vector<vector<int>> segments;
    vector<int> multiplicatifs;
    segments.push_back({});
    for (auto [op, x] : ops) {
        if (op) {
            sort(segments.back().rbegin(), segments.back().rend());
            segments.push_back({});
            multiplicatifs.push_back(x);
        } else {
            segments.back().push_back(x);
        }
    }
    sort(segments.back().rbegin(), segments.back().rend());
    int nbSegments = segments.size();
    vector<vector<int>> prefSum(nbSegments);
    for (int i =0; i < nbSegments; ++i) {
        int len = segments[i].size();
        prefSum[i].resize(len+1);
        for (int j = 0; j < len; ++j)
            prefSum[i][j+1] = prefSum[i][j] + segments[i][j];
    }

    int nbMultiplicatifs = multiplicatifs.size();
    assert(nbMultiplicatifs <= 30);
    vector<int> posGrand, pos2;
    for (int i = 0; i < nbMultiplicatifs; ++i) {
            if (multiplicatifs[i] > 2)
                posGrand.push_back(i);
            else
                pos2.push_back(i);
    }
    int nbGrands = posGrand.size();
    int nb2 = pos2.size();

    int sol = 0;
    vector<int> facteurs(nbSegments);
    vector<int> M(nbMultiplicatifs);
    for (int mskGrand = 0; mskGrand < (1 << nbGrands); ++mskGrand) {
        int argent = budget;
        argent -= coutFois * __builtin_popcount(mskGrand);
        for (int prend2 = 0; argent >= 0 and prend2 <= nb2; ++prend2, argent -= coutFois) {
            int prendPlus = argent / coutPlus;

            int cur2 = 0;
            int curGrand = 0;
            int aAjouter = 1;
            for (int i = 0; i < nbMultiplicatifs; ++i) {
                if (multiplicatifs[i] > 2) {
                    if ((1 << curGrand) & mskGrand)
                        M[i] = 1, aAjouter *= multiplicatifs[i];
                    else
                        M[i] = multiplicatifs[i];
                    assert(posGrand[curGrand] == i);
                    curGrand++;
                } else {
                    if (cur2 >= prend2)
                        M[i] = 2;
                    else
                        M[i] = 1, aAjouter *= 2;
                    cur2++;
                }
            }
            facteurs[nbSegments-1] = aAjouter;
            for (int i = nbSegments-2; i >= 0; --i)
                facteurs[i] = facteurs[i+1] * M[i];
            int factTot = facteurs[0];
            for (int &f : facteurs)
                f = factTot - f;
            
            auto countSuperieur = [&](int borne) -> pair<int, int> {
                int sol = 0;
                int sum = 0;
                for (int seg = 0; seg < nbSegments; ++seg) {
                    if (segments[seg].empty() or segments[seg][0] * facteurs[seg] < borne)
                        continue;
                    int lo = 0, up = segments[seg].size() - 1;
                    while (lo < up) {
                        int mid = (lo + up + 1) / 2;
                        if (facteurs[seg] * segments[seg][mid] >= borne)
                            lo = mid;
                        else
                            up = mid-1;
                    }
                    sol += lo+1;
                    sum += facteurs[seg] * prefSum[seg][lo+1];
                }
                return pair(sol, sum);
            };

            int lo = 0, up = 4e18;
            while (lo < up) {
                int mid = (lo + up + 1) / 2;
                int cnt = countSuperieur(mid).first;
                if (cnt < prendPlus)
                    up = mid-1;
                else
                    lo = mid;
            }
            auto [cnt, sum] = countSuperieur(lo);
            int exces = cnt - prendPlus;
            assert(exces >= 0);
            sum -= lo * exces;
            for (int seg = 0; seg < nbSegments; ++seg)
                sum += (factTot - facteurs[seg]) * prefSum[seg].back();
            sol = max(sol, sum);
        }
    }
    cout << sol << endl;
}