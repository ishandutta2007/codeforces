/*
 *      Author: arsijo;
 *      made in Ukraine
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    bool bol[n];
    for(int i = 0; i < n; i++)
        bol[i] = false;
    int bestScore [m];
    vector<int> bestPupil [m];
    for(int i = 0; i < m; i++){
        bestPupil[i].clear();
        bestScore[i] = -1;
    }
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            int g = s[j] - '0';
            if (g > bestScore[j]){
                bestScore[j] = g;
                bestPupil[j].clear();
                bestPupil[j].insert(bestPupil[j].end(), i);
            }else if (g == bestScore[j]){
                bestPupil[j].insert(bestPupil[j].end(), i);
            }
        }
    }
    for(int i = 0; i < m; i++){
        for (int j = 0; j < bestPupil[i].size(); j++){
            bol[bestPupil[i][j]] = true;
        }

    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (bol[i])
            ans++;
    }
    cout << ans;
}