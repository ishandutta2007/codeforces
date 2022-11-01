#include <bits/stdc++.h>
 
using namespace std;

double s, x1, x2, t1, t2, p;
int d;

int main () {
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
    double r = abs(x1 - x2) * t2;
    // cout << r << endl;
    if (t1 >= t2) {
        int z = floor(r + 0.5);
        printf("%d\n", z);
        return 0;
    }
    if (x1 > x2) {
        x1 = s - x1;
        x2 = s - x2;
        p = s - p;
        d *= -1;
    }
    if (p >= x1) {
        // cout << "yo\n";
        if (p == x1) {
            if (d == 1) r = min(r, abs(x1 - x2) * t1);
            else r = min(r, (x1 + x2) * t1);
        }
        if (d == 1) {
            double dis = ((2.0 * s - p) * t1 + x1 * t2)/(t1 + t2);
            double tim1 = abs(dis - x1) * t2;
            double tim2 = abs(dis + x2) * t1;
            r = min(r, tim1 + tim2);
        } else {
            // cout << "yo\n";
            double dis = (p * t1 + x1 * t2)/(t1 + t2);
            // cout << dis << endl;
            double tim1 = abs(dis - x1) * t2;
            double tim2 = abs(dis + x2) * t1;
            r = min(r, tim1 + tim2);
        }
    } else {
        if (d == 1) {
            double dis = (p * t1 + x1 * t2)/(t1 + t2);
            double tim1 = abs(x1 - dis) * t2;
            double tim2 = abs(dis - x2) * t1;
            r = min(r, tim1 + tim2);
            dis = (p * t1 - x1 * t2)/(t1 - t2);
            tim1 = abs(dis - x1) * t2;
            tim2 = abs(dis - x2) * t1;
            r = min(r, tim1 + tim2); 
        } else {
            double dis = (x1 * t2 - p * t1)/(t1 + t2);
            double tim1 = abs(x1 - dis) * t2;
            double tim2 = abs(dis - x2) * t1;
            r = min(r, tim1 + tim2);
            dis = (p * t1 + x1 * t2)/(t2 - t1);
            tim1 = abs(dis - x1) * t2;
            tim2 = abs(dis - x2) * t1;
            r = min(r, tim1 + tim2); 
        }
    }
    int z = floor(r + 0.5);
    printf("%d\n", z);
    return 0;
}