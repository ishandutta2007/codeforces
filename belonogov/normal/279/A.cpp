#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 

const int maxn = -1;
const int inf = (int)1e9;



int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0){
        cout << "0\n";
        return 0;
    }
    if (x + y > 1 && x - y >= 0)
        cout << (x - 1) * 4 + 1 << endl;
    if (x - y < 0 && x + y >= 0)
        cout << (y - 1) * 4 + 2 << endl;
    if (x + y < 0 && y - x >= 0)
        cout << (- x - 1) * 4 + 3 << endl;
    if (y - x < 0 && x + y <= 1)
        cout << (- y - 1) * 4 + 4 << endl;

    return 0;
}