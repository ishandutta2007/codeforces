
using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;

int gr[1000][1000];
int gr2[1000][1000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    int tests;
    cin >> tests;
    for (int casenum = 1; casenum <= tests; casenum++) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                x--;
                gr[i][j] = x;
            }
        }
        vector<char> cs = { 'i', 'j', 'x' };
        vector<int> offs = { 0,0,0 };
        string s;
        cin >> s;
        for (char c : s) {
            if (c == 'R') offs[1]++;
            if (c == 'U') offs[0]--;
            if (c == 'L') offs[1]--;
            if (c == 'D') offs[0]++;
            if (c == 'I') {
                swap(cs[1], cs[2]);
                swap(offs[1], offs[2]);
            }
            if (c == 'C') {
                swap(cs[0], cs[2]);
                swap(offs[0], offs[2]);
            }
        }
        offs[0] = (offs[0] % n) + n;
        offs[1] = (offs[1] % n) + n;
        offs[2] = (offs[2] % n) + n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = gr[i][j];
                if (cs[0] == 'i' && cs[1] == 'j') {
                    gr2[(i + offs[0]) % n][(j + offs[1]) % n] = (x + offs[2]) % n;
                }
                if (cs[0] == 'j' && cs[1] == 'i') {
                    gr2[(j + offs[0]) % n][(i + offs[1]) % n] = (x + offs[2]) % n;
                }
                if (cs[0] == 'i' && cs[1] == 'x') {
                    gr2[(i + offs[0]) % n][(x + offs[1]) % n] = (j + offs[2]) % n;
                }
                if (cs[0] == 'j' && cs[1] == 'x') {
                    gr2[(j + offs[0]) % n][(x + offs[1]) % n] = (i + offs[2]) % n;
                }
                if (cs[0] == 'x' && cs[1] == 'j') {
                    gr2[(x + offs[0]) % n][(j + offs[1]) % n] = (i + offs[2]) % n;
                }
                if (cs[0] == 'x' && cs[1] == 'i') {
                    gr2[(x + offs[0]) % n][(i + offs[1]) % n] = (j + offs[2]) % n;
                }
            }
        }for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << gr2[i][j]+1 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

}