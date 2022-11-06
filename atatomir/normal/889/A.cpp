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

#define maxN 200011

int n, i, ans;
int x[maxN];
bool used[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    used[0] = true;
    for (i = 1; i <= n; i++) {
        cin >> x[i];
        if (used[x[i]])
            ans++;
        else
            used[x[i]] = true;
    }

    cout << ans;


    return 0;
}