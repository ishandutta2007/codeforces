#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define M 200

int n, a[M], m=0, x[M];
int c = 0, j = 0;


int main(){
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    cin >> n;
    for (int i = 0, h; i < n; ++i){
        cin >> h;
        for (int k = 1; k <= h; ++k)
            cin >> a[k];
        int t = h / 2;

        for (int k = 1; k <= t; ++k)
            c += a[k];
        for (int k = h; k>h - t; --k)
            j += a[k];

        if (h % 2 == 1)
            x[m++] = a[(h + 1) / 2];
        
    }

    sort(x, x + m);
    reverse(x, x + m);

    for (int i = 0; i < m; i += 2)
        c += x[i];
    for (int i = 1; i < m; i += 2)
        j += x[i];

    cout << c << " " << j << "\n";

    return 0;
}