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

const int maxn = 1e6;
const int inf = (int)1e9;

int a[maxn];
set < int > b;


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for(int i = 0; i < n; i++)
        if (!(a[i] % k == 0 && b.find(a[i] / k) != b.end()))
            b.insert(a[i]);
    cout << b.size() << endl;
    

    return 0;
}