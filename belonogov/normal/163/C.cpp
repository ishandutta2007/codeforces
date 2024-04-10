#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;
#define forn(i, n) for(i = 0; i < n; i++)
struct node {
    ld x;
    int i;
};
node a[500000];
ld ans[200000];
int uk = 0;
bool less0(node a, node b){
    return a.x < b.x;
}
int main()
{
   ll i, l, v1, v2, n;
    int x, k;
    long double t, s, pred;
    cin >> n >> l >> v1 >> v2;
    t = (l * 1.0) / (v1 + v2);
    s = (t * v2);
    forn(i, n){
        scanf("%d", &x);
        a[uk].x = x - s;
        a[uk++].i = 1;
        a[uk].x = x;
        a[uk++].i = 0;
        a[uk].x = x + 2 * l - s;
        a[uk++].i = 1;
        a[uk].x = x + 2 * l;
        a[uk++].i = 0;

    }
    sort(a, a + uk, less0);
    i = 0;
    k = 0;
    while(i < uk && a[i].x < 0){
        i++;
        k++;
    }
    pred = 0;
   // if (i != 0)
    //    pred = a[i - 1].x;
    for(; a[i].x < 2 * l && i < uk; i++){
        ans[k] += a[i].x - pred;
        if (a[i].i == 1)
            k++;
        if (a[i].i == 0)
            k--;
        pred = a[i].x;
   }
   ans[k] += 2 * l - pred;
     forn(i, n + 1){
    cout.precision(15);
  
        cout << fixed << (ans[i] * 1.0) / (2 * l) << "\n";
   }

    return 0;
}