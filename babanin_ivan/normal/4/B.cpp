#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int a[40];
int minx[40], maxx[40];

int main() {
    //freopen("input.txt" ,"r", stdin);
    //freopen("output.txt" ,"w", stdout);
    int n, x;
    scanf("%d %d", &n, &x);
    int summin, summax;
    summin = summax = 0;
    for (int i = 0; i < n; ++i) {
        //int , y;
        scanf("%d %d", &minx[i], &maxx[i]);
        summin += minx[i];
        summax += maxx[i];
    }
    if (x >= summin && x <= summax) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i)
            a[i] = minx[i];
        x -= summin;
        for (int i = 0; i < n; ++i) {
            int y = maxx[i] - minx[i];
            a[i] += min(x, y);
            x = max(0, x - y);
        }
        for (int i = 0; i < n; ++i)
            printf("%d ", a[i]);
    }
    else cout << "NO";
}