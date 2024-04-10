#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const long double eps = 1e-11;
struct node{
    long double v;
    int i;
    int m;
};
node v[100010];
long double h[100010];
int n, k;
int ans[100010];
bool f(long double t){
    int i;
    int uk = n - 1;
    for (i = k; i > 0; i--){
        while (uk >= 0 && v[uk].v * t + eps < i)
            uk--;
        if (uk <= -1)
            return false;
        uk--;
    }
    return true;

}

bool less0(node a, node b){
    return a.m < b.m || (a.m == b.m && a.v < b.v);
}

int main(){
    long double r, l, q;
    int w, i;
    int uk;
    cin >> n >> k >> q;
    for (i = 0; i < n; i++)
        scanf("%d", &v[i].m);
    for (i = 0; i < n; i++){
        scanf("%d", &w);
        v[i].v = w / q;
        v[i].i = i;
    }
    sort(v, v + n, less0);

    l = 0;
    r = 20000000000;
   // while(r - l > eps){
       for (i = 0; i < 100; i++){
        if (f((l + r) / 2))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    uk = n - 1;
    for (i = k; i > 0; i--){
        while (uk >= 0 && v[uk].v * r + eps < i)
            uk--;
        ans[i - 1] = v[uk].i;

        uk--;
    }
    for (i = 0; i < k; i++)
        printf("%d ", ans[i] + 1);

        return 0;
}