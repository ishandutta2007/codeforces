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
        vector<int> ans;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "? " << 1 << " " << n - i - 1 << endl;
            cout << i + 1 << endl;
            for (int j = i + 2; j <= n; j++) {
                cout << j << " ";
            }
            cout << endl;
            int x;
            cin >> x;
            if (x != 0) {
                //found a magnet
                if (i != 0) {
                    /*cout << "? " << 1 << " " << i << endl;
                    cout << i + 1 << endl;
                    for (int j = 0; j < i; j++) {
                        cout << j + 1 << " ";
                    }
                    cout << endl;
                    int y;
                    cin >> y;
                    if (y == 0) {
                        for (int j = 0; j < i; j++) {
                            ans.push_back(j + 1);
                        }
                    }
                    else {*/
                        int lo = 0;
                        int hi = i - 1;
                        while (hi - lo >= 1) {
                            int md = (hi + lo) / 2;
                            cout << "? " << 1 << " " << md - lo + 1 << endl;
                            cout << i + 1 << endl;
                            for (int j = lo; j <= md; j++) {
                                cout << j + 1 << " ";
                            }
                            cout << endl;
                            int z;
                            cin >> z;
                            if (z != 0) hi = md;
                            else lo = md + 1;
                        }
                        if (lo == i - 1) {
                            cout << "? " << 1 << " " << 1 << endl;
                            cout << i + 1 << endl;
                            cout << i << endl;
                            int z;
                            cin >> z;
                            if (z == 0) lo = -5;
                        }
                        for (int j = 0; j < i; j++) {
                            if (j != lo)
                                ans.push_back(j + 1);
                        }
                    //}
                }

                for (int j = i + 1; j < n-1; j++) {
                    cout << "? " << 1 << " " << 1 << endl;
                    cout << i + 1 << endl;
                    cout << j + 1 << endl;
                    int y;
                    cin >> y;
                    if (y == 0) ans.push_back(j + 1);
                    x -= y;
                }
                if (x == 0) {
                    ans.push_back(n );
                }
                break;
            }
        }
        cout << "! " <<  ans.size() << " ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;

    }

}