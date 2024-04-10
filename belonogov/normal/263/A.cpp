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


using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr ()
#endif 


typedef long long ll;
typedef vector < int > vi;

const int maxn = (int)2e5;
const int inf = (int)1e9;


int main(){
//     freopen("in", "r", stdin);
// //     freopen("out", "w", stdout);
    int x;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++){
            scanf("%d", &x);
            if (x == 1){
    printf("%d\n", abs(i - 2) + abs(j - 2));
            }
        }

    return 0;
}