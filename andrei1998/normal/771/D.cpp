#include <iostream>
#include <string>
#include <vector>

//11:15
using namespace std;

const int NMAX = 75 + 5;
const int INF = NMAX * NMAX * NMAX * NMAX;

int N;
string str;

int dp[NMAX][NMAX][NMAX][2];

void upd(int &where, int val) {
    if (val < where)
        where = val;
}

vector <int> freqV;
vector <int> freqK;
vector <int> freqX;

int getCount(const vector <int> &v, int start, int atMost) {
    /*int cost = 0;
    for (int i = start; i < v.size(); ++ i)
        if (v[i] < atMost)
            ++ cost;
        else
            break;
    return cost;*/

    int firstBad = lower_bound(v.begin(), v.end(), atMost) - v.begin();
    if (start >= firstBad)
        return 0;
    else
        return firstBad - start;
}

int main()
{
    cin >> N;
    cin >> str;
    str = " " + str;

    int cntV = 0;
    int cntK = 0;
    int cntX = 0;


    for (int i = 1; i <= N; ++ i)
        if (str[i] == 'V') {
            ++ cntV;
            freqV.push_back(i);
        }
        else if (str[i] == 'K') {
            ++ cntK;
            freqK.push_back(i);
        }
        else {
            ++ cntX;
            freqX.push_back(i);
        }

    for (int v = 0; v <= cntV; ++ v)
        for (int k = 0; k <= cntK; ++ k)
            for (int x = 0; x <= cntX; ++ x)
                for (int lastV = 0; lastV < 2; ++ lastV)
                    dp[v][k][x][lastV] = INF;

    dp[0][0][0][0] = 0;
    for (int v = 0; v <= cntV; ++ v)
        for (int k = 0; k <= cntK; ++ k)
            for (int x = 0; x <= cntX; ++ x)
                for (int lastV = 0; lastV < 2; ++ lastV) {
                    //Add V
                    if (v < cntV) {
                        int cost = getCount(freqK, k, freqV[v]) +
                                   getCount(freqX, x, freqV[v]);
                        upd(dp[v + 1][k][x][1], dp[v][k][x][lastV] + cost);
                    }

                    //Add K
                    if (k < cntK && !lastV) {
                        int cost = getCount(freqV, v, freqK[k]) +
                                   getCount(freqX, x, freqK[k]);
                        upd(dp[v][k + 1][x][0], dp[v][k][x][lastV] + cost);
                    }

                    //Add X
                    if (x < cntX) {
                        int cost = getCount(freqV, v, freqX[x]) +
                                   getCount(freqK, k, freqX[x]);
                        upd(dp[v][k][x + 1][0], dp[v][k][x][lastV] + cost);
                    }
                }

    cout << min(dp[cntV][cntK][cntX][0], dp[cntV][cntK][cntX][1]) << '\n';
    return 0;
}