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
mt19937 rr(random_device{}());
    
int main() {
    // freopen("jackpot.in", "r", stdin);
    // freopen("jackpot.out", "w", stdout);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //ifstream cin("breakfree.in");
    //ofstream cout("breakfree.out");

    int n;
    cin >> n;
    int k[2];
    vector<vector<int>> s(n, vector<int>(2));

    for (int j = 0; j < 2; ++j) {
        cin >> k[j];
        for (int i = 0; i < k[j]; ++i)
            cin >> s[i][j];
    }

    vector<vector<int>> w(n, vector<int>(2, -1));

    vector<vector<int>> cnt(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cnt[i][0] = k[0];
        cnt[i][1] = k[1];
    }
    queue<pair<int, int>> q;
    w[0][0] = 0;
    w[0][1] = 0;
    q.push({0, 0});
    q.push({0, 1});

    while (!q.empty()) {
        int u = q.front().first; // place
        int v = q.front().second; // player
        q.pop();

        if (w[u][v] == 0) {
            for (int i = 0; i < k[1 - v]; ++i) {
                int y = 1 - v;
                int x = (u - s[i][y] + n) % n;
                if (w[x][y] != -1)
                    continue;
                w[x][y] = 1;
                q.push({x, y});
            }
        } else {
            for (int i = 0; i < k[1 - v]; ++i) {
                int y = 1 - v;
                int x = (u - s[i][y] + n) % n;
                if (w[x][y] != -1)
                    continue;
                --cnt[x][y];
                if (cnt[x][y] == 0) {
                    w[x][y] = 0;
                    q.push({x, y});
                }
            }
        }
    }

    for (int j = 0; j < 2; ++j) {
        for (int i = 1; i < n; ++i) {
            if (w[i][j] == 1) {
                cout << "Win ";
            } else if (w[i][j] == 0) {
                cout << "Lose ";
            } else {
                cout << "Loop "; 
            }
        }
        cout << endl;
    }
        
}