#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 2020;

char c[maxn][maxn];
vector<pair<int, int> > vc;

int dx[] = {-1, -1, -1 , 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {

    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("\n");
        for(int f = 0; f < m; f++) {
            c[i][f] = getchar();
        }
    }

    for(int i = 0; i < n - 1; i++) {
        for(int f = 0; f < m - 1; f++) {
            if((c[i][f] == '*') + (c[i + 1][f] == '*') + (c[i][f + 1] == '*') + (c[i + 1][f + 1] == '*') == 1) {
                vc.push_back(make_pair(i, f));
            }
        }
    }
    while(!vc.empty()) {
        int i = vc.back().first, f = vc.back().second; vc.pop_back();
        if((c[i][f] == '*') + (c[i + 1][f] == '*') + (c[i][f + 1] == '*') + (c[i + 1][f + 1] == '*') == 1) {
            c[i][f] = '.';
            c[i + 1][f] = '.';
            c[i][f + 1] = '.';
            c[i + 1][f + 1] = '.';
            for(int g = 0; g < 8; g++) {
                if(i + dx[g] >= 0 && i + dx[g] < n - 1 && f + dy[g] >= 0 && f + dy[g] < m - 1)
                if((c[i + dx[g]][f + dy[g]] == '*') + (c[i + dx[g] + 1][f + dy[g]] == '*') + (c[i + dx[g]][f + dy[g] + 1] == '*') + (c[i + dx[g] + 1][f + dy[g] + 1] == '*') == 1) {
                    vc.push_back(make_pair(i + dx[g], f + dy[g]));
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%s\n", c[i]);
    }

    return(0);
}

// by Kim Andrey