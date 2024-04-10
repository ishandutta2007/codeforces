#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int n;
vector <string> a;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d ", &n);
    for (int t = 0; t < n; ++t) {
        string s1;
        cin >> s1;
        if (s1 == "pwd") {
            printf("/");
            for (int j = 0; j < a.size(); ++j) 
                printf("%s/", a[j].c_str());
            printf("\n");
            continue;
        }
        cin >> s1;
        int j = 0;
        if (s1[0] == '/') {
            a.clear();
            ++j;
        }
        while (j < s1.size()) {
            string t;
            t.clear();
            while ((j < s1.size()) && (s1[j] != '/')) {
                t.pb(s1[j]);
                ++j;
            }
            if (t == "..")
                a.pop_back();
            else a.pb(t);
            if (s1[j] == '/')
                ++j;
        }
    }
    return 0;
}