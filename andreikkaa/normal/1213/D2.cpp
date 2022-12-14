#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n = 0, k = 0;
    int x;
    cin >> n >> k;
    vector <int> a(200001);

    for (int i = 0; i < 200001; i++) {
        a[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }

    int minim = 2147483640;
    int cnt, summa, l, r, t;

    for (int i = 1; i < 200001; i++) {

        cnt = 0;
        summa = a[i];
        l = i*2;
        r = i*2 + 1;
        t = 1;

        while ((l <= 200000) && (k > summa)) {
            if (r > 200000) {
                r = 200000;
            }
            for (int j = l; j <= r; j++) {
                cnt += t*a[j];
                summa += a[j];
            }
            l = 2*l;
            r = 2*r + 1;
            t++;
        }
        if (summa >= k) {
            minim = min((cnt - (summa - k)*(t-1)), minim);
        }
    }

    cout << minim;

    return 0;
}