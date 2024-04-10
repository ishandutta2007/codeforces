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


set < int > q;

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, d;
    cin >> n;
    for(int i = n + 1; true; i++){
        d = i;
        q.clear();
        for(int j = 0; j < 4; j++, d /= 10)
            q.insert(d % 10);
        if ((int)q.size() == 4){
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}