#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int INF = 1e9;
const int MAXN = 1111;

int nxt[MAXN][2 * MAXN];

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for (int i = 0; i <= n; ++i) {
        for (int j = -k - 1; j <= k + 1; ++j) {
            nxt[i][j + k + 1] = INF;
        }
    }
        
    nxt[n][2 * k + 1] = 0;
    nxt[n][1] = 0;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = -k + 1; j <= k - 1; ++j) {
            if (s[i] == 'L' || s[i] == '?') {

                if (nxt[i + 1][j + k + 1 - 1] != INF)
                    nxt[i][j + k + 1] = -1;

            }  

            if (s[i] == 'W' || s[i] == '?') {

                if (nxt[i + 1][j + k + 1 + 1] != INF)
                    nxt[i][j + k + 1] = 1;

            }

            if (s[i] == 'D' || s[i] == '?') {

                if (nxt[i + 1][j + k + 1] != INF)
                    nxt[i][j + k + 1] = 0;

            } 
        }
    }

    // for (int i = 0; i <= n; ++i) {
    //     for (int j = -k; j <= k; ++j)
    //         cout << nxt[i][j + k + 1] << " ";
    //     cout << endl;
    // }
    // cout << endl;

    if (nxt[0][k + 1] == INF) {
        cout << "NO" << endl;
        return 0;
    } 

    string res;
    int cur = k + 1;
    for (int i = 0; i < n; ++i) {
        res += (nxt[i][cur] == 1 ? 'W' : (nxt[i][cur] == -1 ? 'L' : 'D'));
        cur += nxt[i][cur];
    } 
    cout << res << endl;
    return 0;
}