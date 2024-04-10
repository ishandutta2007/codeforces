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

const int maxn = 1e5;
const int inf = 1e9;
const int p = 1e9 + 7;


char s[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    scanf("%s", s);
    long long n = strlen(s);
    long long ans = 0, st = 1;
    for(int i = n - 1; i >= 0; i--){
    ans = (ans * 2) % p;
    if (s[i] == '1')
        ans = (ans + st) % p; 
    st = (st * 4) % p;
    }   
    cout << ans << endl;
    return 0;
}