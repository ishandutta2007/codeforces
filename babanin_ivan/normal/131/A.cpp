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

bool is_big(char c) {
    if ((c >= 'A') && (c <= 'Z'))
        return true;
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    getline(cin, s);
    bool f = true;
    for (int i = 1; i < s.size(); ++i)
        if (!is_big(s[i]))
            f = false;
    if (f) {
        for (int i = 0; i < s.size(); ++i)
            if (is_big(s[i]))
                s[i] = 'a' + (s[i] - 'A');
            else s[i] = 'A' + (s[i] - 'a');
    }
    cout << s << endl;
    return 0;
}