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

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    getline(cin, s);
    n = s.size();
    int i = 0;
    while (i < n) {
        int cur = 0;
        int j = i;
        while ((j < n) && (s[j] == s[i])) {
            ++cur;
            ++j;
        }
        if (cur > 6) {
            printf("YES\n");
            return 0;
        }
        i = j;
    }
    printf("NO\n");
    return 0;
}