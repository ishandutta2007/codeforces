#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int n, m;

string S[333][333], SS[333][333], T[333][333]; // use brute force

int NwS[333], oriS[333][333], oriT[333][333], nwLS[333][333], nwLT[333][333];

int Ans1[555555][4], t1 = 0, Ans2[555555][4], t2 = 0;

void Do1(int a1, int b1, int a2, int b2) {
    //if(a1 == a2 && b1 == b2) return;
    //S[a2][b2] = S[a1][b1].back() + S[a2][b2];
    nwLS[a2][b2]++;
    nwLS[a1][b1]--;
    t1++;
    Ans1[t1][0] = a1;
    Ans1[t1][1] = b1;
    Ans1[t1][2] = a2;
    Ans1[t1][3] = b2;
    //S[a1][b1].pop_back();
}

void Do2(int a1, int b1, int a2, int b2) {
    //if(a1 == a2 && b1 == b2) return;
    //T[a2][b2] = T[a2][b2] + T[a1][b1][0];
    nwLT[a2][b2]++;
    nwLT[a1][b1]--;
    t2++;
    Ans2[t2][0] = a1;
    Ans2[t2][1] = b1;
    Ans2[t2][2] = a2;
    Ans2[t2][3] = b2;
    //T[a1][b1] = T[a1][b1].substr(1, (int) T[a1][b1].size() - 1);
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> S[i][j], oriS[i][j] = S[i][j].size(), SS[i][j] = S[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> T[i][j], oriT[i][j] = T[i][j].size();
    memcpy(nwLS, oriS, sizeof oriS);
    memcpy(nwLT, oriT, sizeof oriT);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            int k = S[i][j].size();
            while(oriS[i][j]--)
                if(S[i][j][--k] == '0') {
                    if(j == 1) Do1(i, j, i == 1 ? n : 1, j);
                    else Do1(i, j, i, 1);
                } else {
                    if(j == m) Do1(i, j, i == 1 ? n : 1, j);
                    else Do1(i, j, i, m);
                }
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            int k = 0;
            while(oriT[i][j]--)
                if(T[i][j][k++] == '0') {
                    if(j == 1) Do2(i, j, i == 1 ? n : 1, j);
                    else Do2(i, j, i, 1);
                } else {
                    if(j == m) Do2(i, j, i == 1 ? n : 1, j);
                    else Do2(i, j, i, m);
                }
        }
    int nwS[333], nwT[333];
    for(int i = 1; i <= n; i++) nwS[i] = nwLS[i][1], nwT[i] = nwLT[i][1];
    {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                while(i != j && nwS[i] > nwT[i] && nwS[j] < nwT[j]) {
                    Do1(i, 1, j, 1);
                    nwS[i]--;
                    nwS[j]++;
                }
        }
    }
    for(int i = 1; i <= n; i++) nwS[i] = nwLS[i][m], nwT[i] = nwLT[i][m];
    {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                while(i != j && nwS[i] > nwT[i] && nwS[j] < nwT[j]) {
                    Do1(i, m, j, m);
                    nwS[i]--;
                    nwS[j]++;
                }
        }
    }
    printf("%d\n", t1 + t2);
    for(int i = 1; i <= t1; i++) printf("%d %d %d %d\n", Ans1[i][0], Ans1[i][1], Ans1[i][2], Ans1[i][3]);
    for(int i = t2; i >= 1; i--) printf("%d %d %d %d\n", Ans2[i][2], Ans2[i][3], Ans2[i][0], Ans2[i][1]);
    return 0;
}