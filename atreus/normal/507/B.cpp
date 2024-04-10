#include<bits/stdc++.h>

using namespace std;

int main (){
    int r, x, y, x1, y1;
    cin >> r >> x >> y >> x1 >> y1;
    if (x1 > x)
        swap(x, x1);
    int xi = x - x1;
    if (y1 > y)
        swap(y, y1);
    int yi = y - y1;
    double h = (1ll * xi * xi) + (1ll * yi * yi);
    h = sqrt(h);
    int qot = 2 * r;
    for (int i = 0; i < 10000000; i++){
        if (qot * i >= h){
            cout << i << endl;
            return 0;
        }
    }
}