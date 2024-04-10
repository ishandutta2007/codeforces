#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;
const int dx[9] = {1, -1, 0, 0, 1, -1, 1, -1, 0};
const int dy[9] = {0, 0, 1, -1, -1, 1, 1, -1, 0};

bool a[3][20][20];
bool dp[500][20][20];

void print() {
    cout << "WIN" << endl;
    exit(0);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j) {
            char c;
            scanf(" %c ", &c);
            if (c == 'S')
                a[0][i][j] = true;
        }
    dp[0][7][0] = true;
    int t = 0;
    for (int z = 0; z < 300; ++z) {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                a[!t][i][j] = false;
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                if (a[t][i][j])
                    a[!t][i + 1][j] = true;
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                if (dp[z][i][j])
                    for (int x = 0; x < 9; ++x)
                        if (((i + dx[x]) >= 0) && ((i + dx[x]) < 8) && ((j + dy[x]) >= 0) && ((j + dy[x]) < 8) && (!a[!t][i + dx[x]][j + dy[x]]) && (!a[t][i + dx[x]][j + dy[x]]))
                            dp[z + 1][i + dx[x]][j + dy[x]] = true;
        if (dp[z + 1][0][7])
            print();
        t = !t;
    }
    cout << "LOSE\n";
    return 0;
}