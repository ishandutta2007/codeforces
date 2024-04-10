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

int ans[200000];
int n;
int a[200000];

void print() {
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
    exit(0);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);
    if (n == 1) {
        if (a[0] == 1)
            ans[0] = 2;
        else ans[0] = 1;
        print();
    }
    bool f = false;
    if (a[n - 1] == 1) {
        for (int i = 0; i < n; ++i)
            ans[i] = 1;
        ans[n - 1] = 2;
        print();
    }
    for (int i = 0; i < n; ++i)  
        if (a[i] > 1) {
            if (i > 0)
                ans[i] = a[i - 1];
            else ans[i] = 1;
        }
        else ans[i] = 1;
    print();
    return 0;
}