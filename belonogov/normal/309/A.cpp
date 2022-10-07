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

const int maxn = 1e6 + 5;
const int inf = 1e9;

int a[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, t, l, kof, cur, d;
    long double ans = 0;
    scanf("%d%d%d", &n, &l, &t);
    if (n == 1){
    printf("0\n");
    return 0;
    }
    for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
    t *= 2;
    
    ans = (1.0 * n * (n - 1) / 4) * (t / l);
    d = t % l;
    kof = 1;
    cur = 0;
    for(int i = 0; i < n; i++){
        if (cur == i) cur = (cur + 1) % n;
           
        for(; ; cur = (cur + 1) % n){
            if (i < cur){
                if (a[cur] - a[i] > d) 
                    break;
            }
            else{
                if (a[cur] + (l - a[i]) > d)
                    break;
            }
        }
        ans += ((cur - i - 1 + n) % n) * 0.25 * kof;

    }       
//     cerr << "ans " << ans << "\n";
    
    cout.precision(15);
    cout << fixed << ans << "\n";
    
    
    
    return 0;
}