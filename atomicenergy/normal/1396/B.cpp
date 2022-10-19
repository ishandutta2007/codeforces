
using namespace std;

//#define fileio

#ifndef fileio
#include <iostream>
#endif
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

typedef long long ll;

#ifdef fileio
ifstream cin;
ofstream cout;
#endif



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef fileio
    cin.open("Text.txt");
    cout.open("Output.txt");
#endif

    int tests;
    cin >> tests;
    for (int casenum = 1; casenum <= tests; casenum++) {
        int n;
        cin >> n;

        vector<int> v;
        ll tot = 0;
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            tot += x;
            mx = max(mx, x);
            v.push_back(x);
        }
        if (tot % 2 != 0) {
            cout << "T" << endl;
            continue;
        }
        if (mx * 2 > tot) {
            cout << "T" << endl;
            continue;
        }
        cout << "HL" << endl;


    }




}