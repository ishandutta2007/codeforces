#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>

#define M 100010

using namespace std;

int n;

map <string, int> mmp;

int cnt = 0;

vector <int> V[M];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        string S1, S2;
        cin >> S1 >> S2;
        string S = "";
        bool B[233];
        memset(B, 0, sizeof B);
        for(int j = 0; j < S2.size(); j++) if(!B[S2[j]]) B[S2[j]] = 1;
        for(int j = 'a'; j <= 'z'; j++) if(B[j]) S += (char) j;
        S += ' ';
        int j = (int) S1.size() - 1;
        for(; j >= 0; j--) if(!B[S1[j]]) break;
        for(int k = 0; k <= j; k++) S += S1[k];
        if(!mmp[S]) mmp[S] = ++cnt;
        V[mmp[S]].push_back(i);
    }
    printf("%d\n", cnt);
    for(int i = 1; i <= cnt; i++) {
        printf("%d ", V[i].size());
        for(int j = 0; j < V[i].size(); j++) printf("%d ", V[i][j]);
        putchar('\n');
    }
    return 0;
}