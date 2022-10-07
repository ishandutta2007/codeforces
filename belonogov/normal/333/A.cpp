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



int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    long long n;
    cin >> n;
    for(; n % 3 == 0; n /= 3);
    cout << (n + 2) / 3 << endl;;
    
    
    return 0;
}