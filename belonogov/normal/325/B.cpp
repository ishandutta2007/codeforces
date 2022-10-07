#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = -1;
const int inf = 2e9;

long long sum;

long long check(int k, long long n){
    if (1.0 * n * (n - 1 + ((1ll << k) - 1) * 2) / 2 > 2 * 1e18)
        return -1;
    return n * (n - 1 + ((1ll << k) - 1) * 2) / 2;
}

int main(){
   // freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);
    long long l, r, val;
    cin >> sum;
   // cout << check(30, inf) << endl;
    //cerr << "0\n";
    bool flag = 0;
    for(int k = 0; (1ll << k) - 10 < sum; k++){
        //cerr << "1\n";
        l = -1;
        r = inf;
        while (r - l > 1){
            val = check(k, (l + r) / 2);
            if (val == -1 || val >= sum)
                r = (l + r) / 2;
            else
                l = (l + r) / 2;
        }
      //
        cerr << "k r l " << k << " " << l << " " << r << endl;
        val = check(k, r);
        if (val == sum && r % 2 == 1){
            cout << (1ll << k) * r << endl;
            flag = 1;
        }
    }
    if (flag == 0){
        cout << "-1\n";
    }
    return 0;
}