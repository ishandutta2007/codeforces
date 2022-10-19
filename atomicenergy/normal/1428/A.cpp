
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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    int tests;
    cin >> tests;
    for (int casenum = 1; casenum <= tests; casenum++) {
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        int dx = abs(ax - bx);
        int dy = abs(ay - by);
        if (dx == 0 || dy == 0) {
            cout << dx + dy << endl;
        }
        else {
            cout << dx + dy + 2 << endl;
        }
    }

}