#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = -1;
const int inf = 1e9;

int f(char ch) {
    if (ch == '(') return 3;
    if (ch == '[') return 2;
    if (ch == '8') return 1; 
    assert(false);
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int cnt = 0, x, y;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < (int)s1.length(); i += 2) {
        x = f(s1[i]);
        y = f(s2[i]);
        if (x == y) continue;
        if (x == 2 && y == 1) cnt++;
        if (x == 2 && y == 3) cnt--;
        if (x == 1 && y == 2) cnt--;
        if (x == 1 && y == 3) cnt++;
        if (x == 3 && y == 1) cnt--;
        if (x == 3 && y == 2) cnt++; 
    }
    if (cnt > 0) {
        printf("TEAM 2 WINS\n");
        return 0;
    }
    if (cnt < 0) {
        printf("TEAM 1 WINS\n");
        return 0;
    }
    if (cnt == 0) {
        printf("TIE\n");
    }


    return 0;
}