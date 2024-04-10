
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


    long long tests;
    cin >> tests;
    for (long long casenum = 1; casenum <= tests; casenum++) {
        long long n;
        cin >> n;

        vector<long long> v;
        long long s = 0;
        for (long long i = 0; i < n; i++) {
            long long x;
            cin >> x;
            v.push_back(x);
            s += x;
        }
        vector<vector<long long> > operations;
        vector<pair<long long, long long> > inds;
        for (long long i = n; i >= 2; i--) {
            if (v[i - 1] >= i) {
                operations.push_back({ i, 1, v[i - 1] / i });
                v[0] += (v[i - 1] / i) * i;
                v[i - 1] -= (v[i - 1] / i) * i;
                i = 0;
                break;
            }
        }

        for (long long i = 2; i <= n; i++) {
            inds.push_back({ (((i - v[i - 1]) % i) + i) % i , i });
        }
        sort(inds.begin(), inds.end());

        for (auto p : inds) {
            //p.first is how much we need to get to a multiple
            //p.second is which index
            if (v[0] < p.first) {
                break;
            }
            operations.push_back({ 1, p.second, p.first });
            operations.push_back({ p.second, 1, (v[p.second - 1]+p.first) / p.second });
            v[0] += v[p.second-1];
            v[p.second - 1] = 0;
        }
        bool possible = true;
        if (s % n != 0) possible = false;
        long long target = s / n;
        //final stage
        for (long long i = 2; i <= n; i++) {
            if (v[i-1] > target) possible = false;
            if(v[i-1] < target) {
                operations.push_back({ 1, i, target - v[i - 1] });
            }
        }

        if (!possible) {
            cout << -1 << endl;
        }
        else {
            cout << operations.size() << endl;
            for (auto v : operations) {
                cout << v[0] << " " << v[1] << " " << v[2] << endl;
            }
        }
    }

}