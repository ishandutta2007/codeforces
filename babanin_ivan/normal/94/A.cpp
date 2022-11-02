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

string s[20];
string a[20];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 10; ++j) {
            char c;
            scanf(" %c ", &c);
            s[i].pb(c);
        }
    for (int i = 0; i < 10; ++i) {
        scanf(" ");
        getline(cin, a[i]);
    }
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 10; ++j)
            if (s[i] == a[j])
                printf("%d", j);
    return 0;
}