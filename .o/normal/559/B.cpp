#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  
#include <unordered_map>
#include <unordered_set>
#include <time.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


void change(string &s, int x, int y) {
    if ((y - x) % 2 == 0) return;
    int m = (x + y) >> 1;
    change(s, x, m);
    change(s, m + 1, y);
    int f = -1;
    for (int i = x, j = m + 1; i <= m && f < 0; i++, j++) {
        if (s[i] < s[j]) f = 0;
        else if (s[i] > s[j]) f = 1;
    }
    if (f == 1) {
        for (int i = x, j = m + 1; i <= m; i++, j++) swap(s[i], s[j]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("559B.in", "r", stdin);
    freopen("559B.out", "w", stdout);
#endif

    string s, t;
    cin >> s >> t;

    change(s, 0, s.length() - 1);
    change(t, 0, t.length() - 1);
    puts(s == t ? "YES" : "NO");
    return 0;
}