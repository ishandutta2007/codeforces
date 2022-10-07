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
    int a, b;
    cin >> a >> b;
    cout << b + a << endl;
    //cout << 10000 << endl;
    return 0;
}