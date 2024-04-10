/*
HACK ME IF YOU CAN!















*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#include <set>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
#define mp make_pair
#define pb push_back
#define fc first
#define sc second
#define all(x) x.begin(), x.end()
#define ll long long
#define ld long double
#define int ll

#define max(a, b) (a > b ? a : b)
#define pi 3.141592653589793238462643383279

using namespace std;

const int MAXN = 10000 + 7;

bool dp[MAXN];
bool two[MAXN];
bool tre[MAXN];

main() {
    #ifdef __linux__
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    #ifndef __linux__
        //
        //
    #endif 
    string s;
    cin >> s;
    int n = s.size();
    dp[n] = true;
    set <string> check;
    vector <string> ans;
    for (int i = n - 1; i > 4; i--) {
        if (dp[i + 2]) {
            string d = "";
            d += s[i];
            d += s[i + 1];
            if (1) {
                if ((!tre[i + 2] && two[i + 2]) && s[i] == s[i + 2] && s[i + 1] == s[i + 3]) {
                    
                } else {
                    if (check.find(d) == check.end()) {
                        ans.push_back(d);
                    }
                    check.insert(d);
                    dp[i] = 1;
                    two[i] = 1;
                }
            }

        }
        if (dp[i + 3]) {
            string d = "";
            d += s[i];
            d += s[i + 1];
            d += s[i + 2];
            if (1) {
                if ((!two[i + 3] && tre[i + 3]) && s[i] == s[i + 3] && s[i + 1] == s[i + 4] && s[i + 2] == s[i + 5]) {

                } else {
                    if (check.find(d) == check.end()) {
                        ans.push_back(d);
                    }
                    check.insert(d);
                    dp[i] = 1;
                    tre[i] = 1;
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << endl;
    }
}