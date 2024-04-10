#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

int n, u[N], a[N][20], b[N][20];
long long res = 0;

int get1(int l, int r) {
    int w = u[r - l + 1];
    return max(a[l][w], a[r-(1<<w)+1][w]);
}

int get2(int l, int r) {
    int w = u[r - l + 1];
    return min(b[l][w], b[r-(1<<w)+1][w]);
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i][0];

    for(int i = 0; i < n; i++)
        cin >> b[i][0];

    for(int p = 1, l = 0; p < n; p *= 2, l++) {
        u[p] = l;
    }

    for(int i = 2; i <= n; i++)
        if(!u[i]) {
            u[i] = u[i-1];
        }

    for(int j = 1; j < 20; j++)
        for(int i = 0; i < n; i++)
            if(i + (1<<j) <= n) {
                a[i][j] = max(a[i][j-1], a[i+(1<<(j-1))][j-1]);
                b[i][j] = min(b[i][j-1], b[i+(1<<(j-1))][j-1]);
            }

    for(int i = 0; i < n; i++)
        if(a[i][0] <= b[i][0]) {
            int l = i, r = n - 1, ll;
            while(l < r) {
                int m = (l + r) >> 1;
                if(get1(i, m) < get2(i, m))
                    l = m + 1;
                else
                    r = m;
            }
            ll = l; l = i; r = n - 1;
            while(l < r) {
                int m = (l + r) >> 1;
                if(l == m) m++;
                if(get1(i, m) > get2(i, m))
                    r = m - 1;
                else
                    l = m;
            }
            if(get1(i, l) == get2(i, l))
                res += l - ll + 1;
        }

    cout << res;
    return 0;
}