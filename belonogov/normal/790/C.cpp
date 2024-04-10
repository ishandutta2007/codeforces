#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 77;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int dp[N][N][N][2];
int type[N];
int pref[3][N];
int n;
string s;

void upd(int& a, int b) {
    a = min(a, b);
}

int getSum(int t, int l, int r) {
    assert(r >= l);
    return pref[t][r] - pref[t][l];
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    cin >> n;
    cin >> s;
    memset(dp, 63, sizeof dp);
    dp[0][0][0][1] = 0;
    vector<int> pos[3];
    for (int i = 0; i < n; i++) {
        if (s[i] == 'V') type[i] = 0;
        else if (s[i] == 'K') type[i] = 1;
        else type[i] = 2;
    } 
    for (int i = 0; i < n; i++) {
        pos[type[i]].pb(i);
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++) {
            pref[i][j + 1] = pref[i][j] + (type[j] == i);
        }

    //int cost[3][3][N][N];
    //for (int i = 0; i < 3; i++) {
        //for (int j = 0; j < 3; j++) {
            //for (int ii = 0; ii < (int)pos[i].size(); ii++) {
                //for (int jj = 0; jj < (int)pos[j].size(); jj++) {
                //}
            //}
        //}
    //}


    for (int i = 0; i <= (int)pos[0].size(); i++) {
        for (int j = 0; j <= (int)pos[1].size(); j++) {
            for (int k = 0; k <= (int)pos[2].size(); k++) {
                for (int t = 0; t < 2; t++) {
                    int prevI = i == 0? -1: pos[0][i - 1];
                    int prevJ = j == 0? -1: pos[1][j - 1];
                    int prevK = k == 0? -1: pos[2][k - 1];

                    if (i < (int)pos[0].size()) {
                        int me = pos[0][i];
                        int cost = 0;
                        if (me > prevJ)
                            cost += getSum(1, prevJ + 1, me);
                        if (me > prevK)
                            cost += getSum(2, prevK + 1, me);
                        upd(dp[i + 1][j][k][0], dp[i][j][k][t] + cost);
                    }

                    if (j < (int)pos[1].size() && t == 1) {
                        int me = pos[1][j];
                        int cost = 0;
                        if (me > prevI)
                            cost += getSum(0, prevI + 1, me);
                        if (me > prevK)
                            cost += getSum(2, prevK + 1, me);
                        //if (i == 0 && j == 0 && k == 0) {
                            //db3(prevI, prevK, me);
                            //db(cost);
                        //}
                        upd(dp[i][j + 1][k][1], dp[i][j][k][1] + cost);
                    }

                    if (k < (int)pos[2].size()) {
                        int me = pos[2][k];
                        int cost = 0;
                        if (me > prevI)
                            cost += getSum(0, prevI + 1, me);
                        if (me > prevJ)
                            cost += getSum(1, prevJ + 1, me);
                        upd(dp[i][j][k + 1][1], dp[i][j][k][t] + cost);
                    }
                }
            }
        }
    }
    //db(getSum(0, 0, 3));
    //db(dp[1][0][0][1]);
    //db(dp[1][1][0][1]);
    //db(dp[2][1][0][1]);
    //db(dp[2][1][0][0]);
    //db(dp[1][1][0][0]);
    //db(dp[0][1][0][1]);

    int answer = min(dp[pos[0].size()][pos[1].size()][pos[2].size()][0], 
                     dp[pos[0].size()][pos[1].size()][pos[2].size()][1]);

    printf("%d\n", answer);
    return 0;
}