#include <bits/stdc++.h>
using namespace std;

bool score[6][6][201][201];
string sol[6][6][201][201];

bool decisive(int a, int b) {
    int matches = a + b;
    int dif = a - b;
    int rem = 5 - matches;
    if(rem < 0)
        return false;
    if(abs(dif) > rem)
        return true;
    return false;
}

string code(int match, int winner, int loser) {
    string pref = " ";
    if(match == 1)
        pref = "";
    return pref + to_string(winner) + ":" + to_string(loser);
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;

    for(int i = 0; i <= 200; i += 1)
        for(int j = 0; j <= 200; j += 1)
            score[0][0][i][j] = false;

    score[0][0][0][0] = true;

    for(int scoreA = 0; scoreA <= 5; scoreA += 1)
        for(int scoreB = 0; scoreB <= 5;scoreB += 1) {
            if(scoreA + scoreB == 0)
                continue;
            if(scoreA + scoreB > 5)
                continue;
            if(scoreA >= 1 and scoreB >= 1 and decisive(scoreA - 1, scoreB) and decisive(scoreA, scoreB - 1))
                continue;
            for(int a = 0; a <= 200; a += 1)
                for(int b = 0; b <= 200; b += 1) {
                    score[scoreA][scoreB][a][b] = false;
                    int maxScore = 25;
                    
                    if(scoreA + scoreB == 5)
                        maxScore = 15;

                    for(int winner = maxScore; winner <= max(a, b); winner += 1) {
                        int left = 0, right = winner - 2;

                        if(winner > maxScore)
                            left = right;

                        for(int loser = left; loser <= right; loser += 1) {
                            // a wins;
                            if(winner <= a and loser <= b and scoreA >= 1) {
                                if(not decisive(scoreA - 1, scoreB) and score[scoreA - 1][scoreB][a - winner][b - loser]) {
                                    score[scoreA][scoreB][a][b] = true;
                                    sol[scoreA][scoreB][a][b] = sol[scoreA - 1][scoreB][a - winner][b - loser] + code(scoreA + scoreB, winner, loser);
                                }
                            }
                            
                            // b wins;
                            if(winner <= b and loser <= a and scoreB >= 1) {
                                if(not decisive(scoreA, scoreB - 1) and score[scoreA][scoreB - 1][a - loser][b - winner]) {
                                    score[scoreA][scoreB][a][b] = true;
                                    sol[scoreA][scoreB][a][b] = sol[scoreA][scoreB - 1][a - loser][b - winner] + code(scoreA + scoreB, loser, winner);
                                }
                            }
                            if(score[scoreA][scoreB][a][b])
                                break;
                        }

                        if(score[scoreA][scoreB][a][b]) {
                            break;
                        }
                    }

                    if(score[scoreA][scoreB][a][b] == false) {
                        sol[scoreA][scoreB][a][b] = "Impossible";
                    }
                }
        }


    while(t--) {
        int a, b; cin >> a >> b;
        string ans = "Impossible";
        int best_dif = -6;
        int best_scoreA = -1, best_scoreB = -1;

        for(int scoreA = 0; scoreA <= 5; scoreA += 1)
            for(int scoreB = 0; scoreB <= 5; scoreB += 1) {
                int dif = scoreA - scoreB;

                if(not decisive(scoreA, scoreB))
                    continue;

                if(score[scoreA][scoreB][a][b]) {
                    if(dif > best_dif) {
                        best_scoreA = scoreA;
                        best_scoreB = scoreB;
                        best_dif = dif;
                        ans = sol[scoreA][scoreB][a][b];
                    }
                }
            }
        
        if(ans != "Impossible")
            cout << code(1, best_scoreA, best_scoreB) << "\n";
        cout << ans << "\n";
    }
}