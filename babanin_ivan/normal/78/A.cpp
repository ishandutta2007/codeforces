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

string s;

int solve() {
    scanf(" ");
    getline(cin, s);
    int x = 0;
    for (int i = 0; i < s.size(); ++i)
        if ((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u'))
            ++x;
    return x;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int x1 = solve();
    int x2 = solve();
    int x3 = solve();
    if ((x1 == 5) && (x2 == 7) && (x3 == 5))
        printf("YES\n");
    else printf("NO\n");
    return 0;
}