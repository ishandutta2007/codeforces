
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
#include <iomanip>
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


    long long tests;
    cin >> tests;
    for (long long casenum = 1; casenum <= tests; casenum++) {
        long long n, l;
        cin >> n >> l;
        long double c1 = 0;
        long double c2 = l;
        long double s1 = 1;
        long double s2 = 1;
        vector<long double> v;
        for (long long i = 0; i < n; i++) {
            long double x;
            cin >> x;
            v.push_back(x);
        }
        long long i1 = 0;
        long long i2 = n-1;

        long double t1 = 0;
        long double t2 = 0;

        while (i1 <= i2) {
            long double newt1 = t1 + (v[i1] - c1) / s1;
            long double newt2 = t2 + (c2 - v[i2]) / s2;
            if (newt1 < newt2) {
                t1 = newt1;
                c1 = v[i1];
                i1++;
                s1++;
                //cout << "!" << s1 << i1 << i2 << endl;
            }
            else {
                t2 = newt2;
                c2 = v[i2];
                i2--;
                s2++;
            }
        }

        if (t1 < t2) {
            c1 += (t2 - t1) * s1;
            t1 = t2;
        }
        else {
            c2 -= (t1 - t2) * s2;
            t2 = t1;
        }
        //cout << t1 << s1 << s2 << endl;
        cout << fixed << setprecision(12) << t1 + (c2 - c1) / (s1 + s2) << endl;

    }

}