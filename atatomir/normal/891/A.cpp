#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 2017
#define inf 1000000000

int n, i, j;
int a[maxN], non, aux, ans;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    ans = inf;

    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) non++;

        aux = a[i];
        for (j = i; j > 0; j--) {
            aux = gcd(aux, a[j]);
            if (aux == 1) {
                ans = min(ans, i - j);
                break;
            }
        }
    }

    if (ans >= inf) {
        cout << -1;
        return 0;
    }

    if (non != n) ans++;
    cout << non + ans - 1;




    return 0;
}