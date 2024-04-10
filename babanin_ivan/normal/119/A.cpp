#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int a[5];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d %d %d", &a[0], &a[1], &n);
    int tek = 0;
    while (true) {
        int c = gcd(a[tek], n);
        if (c > n) {
            cout << !tek << endl;
            return 0;
        }
        n -= c;
        tek = !tek;
    }
    return 0;
}