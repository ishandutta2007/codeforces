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

int n, i, ans;
int a, b, c;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (a = 1; a <= n; a++) {
        for (b = a; b <= n; b++) {
            c = a ^ b;

            if (c < b || c > n) continue;
            if (a + b <= c) continue;
            ans++;
        }
    }

    cout << ans;


    return 0;
}