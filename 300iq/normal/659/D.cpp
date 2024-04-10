#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 30000;
const int K = 10000;


vector <int> x, y;

struct pt {
        int x, y;
};
 
inline int area (pt a, pt b, pt c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
 
inline bool intersect_1 (int a, int b, int c, int d) {
        if (a > b)  swap (a, b);
            if (c > d)  swap (c, d);
                return max(a,c) <= min(b,d);
}
 
bool intersect (pt a, pt b, pt c, pt d) {
        return intersect_1 (a.x, b.x, c.x, d.x)
                    && intersect_1 (a.y, b.y, c.y, d.y)
                            && area(a,b,c) * (double) area(a,b,d) <= 0
                                    && area(c,d,a) * (double) area(c,d,b) <= 0;
}

main() {
    int X, Y;
    int n;
    cin >> n;
    n++;
    for (int i = 0; i < n; i++) {
        cin >> X >> Y;
        x.push_back(X);
        y.push_back(Y);
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        int x1 = x[i - 1], y1 = y[i - 1], x2 = x[i], y2 = y[i], x3 = x[i + 1], y3 = y[i + 1];
        if(x1 == x2){
            ans += ((y1 < y2)&&(x3 < x2)); 
            ans += ((y1 > y2) && (x3>x2));
        } else {
            ans += ((x1 > x2) && (y3 < y2));
            ans += ((x1 <x2) && (y3 > y2));
        }
    }
    cout << ans << endl;
}