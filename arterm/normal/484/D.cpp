#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define M 1000100
#define long long long

long n, a[M], d[M];
int l[M], r[M];

void read() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

inline long mabs(long x) {
    return x < 0 ? -x : x;
}


inline void upd(int j, int i) {
    d[i] = max(d[i], d[j - 1] + mabs(a[i] - a[j]));
}

void din() {
    
    l[1] = r[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i - 1] < a[i])
            l[i] = l[i - 1];
        else
            l[i] = i;

        if (a[i - 1] > a[i])
            r[i] = r[i - 1];
        else
            r[i] = i;
    }  

    d[0] = 0;
    d[1] = 0;

    for (int i = 2; i <= n; ++i) {
        d[i] = 0;
        for (int j = 0; j <= 5 && j < i; ++j)
            upd(i - j, i);

        for (int j = 0; j < 3 && l[i] + j <= i; ++j)
            upd(l[i] + j, i);
        for (int j = 0; j < 3 && r[i] + j <= i; ++j)
            upd(r[i] + j, i);
    }

    cout << d[n] << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);

    read();
    din();

    return 0;
}