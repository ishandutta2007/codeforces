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

#define maxN 2018

int n, i;
int p[maxN], down[maxN], bb[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 2; i <= n; i++) {
        cin >> p[i];
        down[p[i]]++;
    }

    for (i = 2; i <= n; i++) {
        if (down[i] == 0)
            bb[p[i]]++;
    }

    for (i = 1; i <= n; i++) {
        if (down[i] != 0 && bb[i] < 3) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";


    return 0;
}