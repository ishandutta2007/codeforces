
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
        string s;
        vector<char> stack;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                stack.push_back(s[i]);
            }
            else {
                if (stack.size() == 0) {
                    stack.push_back(s[i]);
                }
                else {
                    stack.pop_back();
                }
            }
        }
        cout << stack.size() << endl;
    }

}