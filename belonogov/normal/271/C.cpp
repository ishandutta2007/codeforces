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
    #define epr 
#endif 


typedef long long ll;
typedef vector < int > vi;

const int maxn = -1;
const int inf = (int)1e9;



int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, k;
    cin >> n >> k;
    if (k * 3 > n){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < k; i++)
        printf("%d ", i + 1);
    for(int i = 0; i < k; i++)
        printf("%d %d ", i + 1, i + 1);
    for(int i = k * 3; i < n; i++)
        printf("1 ");
    printf("\n");

    return 0;
}