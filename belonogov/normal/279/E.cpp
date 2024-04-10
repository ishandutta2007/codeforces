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

const int maxn = 1e6 + 10;
const int inf = (int)1e9;

char s[maxn];


int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int ans = 0, n, cnt1 = 0;
    scanf("%s", s);
    n = strlen(s);
    for(int i = n - 1; i >= 0; i--){
        if (s[i] == '1')
            cnt1++;
        if (s[i] == '0' && cnt1 > 0){
            if (cnt1 == 1){
    ans++;
    cnt1 = 0;
            }
            else{
    if (i == 0 || s[i - 1] == '0'){
        ans += 2;
        cnt1 = 0;
    }
    else{
        ans++;
        cnt1++;
    }
            }
        }
        
        
    }
    if (cnt1 == 1) ans++;
    if (cnt1 > 1) ans += 2;
    cout << ans << endl;
        
    
    return 0;
}