#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 1e5 + 10;
const int INF = 1e9 + 10;

int a[N];
int l[N];
int r[N];


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        if (i != 0 && a[i - 1] < a[i])
            l[i] = l[i - 1] + 1;
        else
            l[i] = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1 && a[i + 1] > a[i])
           r[i] = r[i + 1] + 1; 
        else
           r[i] = 1;
    }
    int res = 0;
    //for (int i = 0; i < n; i++)
        //cerr << a[i] << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++)
        //cerr << l[i] << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++)
        //cerr << r[i] << " ";
    //cerr << endl;
    for (int i = 0; i < n; i++) {
        int left = 0 , right = 0;
        int ans = -1;
        int valL, valR;
        if (i != 0) left = l[i - 1];
        if (i != n - 1) right = r[i + 1];
        valL = (i == 0)? -INF: a[i - 1];
        valR = (i == n - 1)? INF: a[i + 1];
        if (valL + 1 < valR)
            ans = left + 1 + right;
        else
            ans = max(left, right) + 1;
        //cerr << "i left right res: " << i << " " << " " << left << " " << right << " " << ans << endl;
        res = max(ans, res);
    }
    printf("%d\n", res);
    return 0;
}