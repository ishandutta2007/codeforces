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

#define maxN 111

int n, i, j, cnt, need, p;
int a[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    while (cnt < n) {
        need = 0; p++;
        for (i = 1; i <= n; i++) {
            if (a[i] >= need) {
                a[i] = -1;
                cnt++;
                need++;
            }
        }
    }

    cout << p;


    return 0;
}