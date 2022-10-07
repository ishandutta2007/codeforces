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

const int maxn = 3999;
const int inf = 1e9;


double a[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, sum2 = 0, l, r, cnt = 0;
    double x, sum = 0;
    double r1, r2;
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];            
        sum2 += (int)a[i];          
        if ((a[i] - (int)a[i]) == 0)
            cnt++;      
    }
    r = min(n / 2, n - cnt);
    l = max(0, n / 2 - cnt);
    
    x = sum - sum2;
    cout.precision(3);
    if (r < x){
        cout << fixed << x - r << endl;
        return 0;
    }
    if (x < l){
        cout << fixed << l - x << endl;
        return 0;       
    }
    r1 = x - (int)x;
    r2 = (int)x + 1 - x;
    cout << fixed << min(r1, r2) << endl;
    
 
    return 0;
}