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
#define fr first
#define sc second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 

const int maxn = -1;
const int inf = (int)1e9;


string s;
int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, x = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        x += (s[1] == '+') ? 1 : -1;
    }
    cout << x << endl;

    return 0;
}