#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

ll n, k, i;
map<ll, bool> M;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> k;
    for (i = 1; i <= k; i++) {
        ll aux = n % i;

        if (M[aux]) {
            cout << "No";
            return 0;
        }
        M[aux] = true;
    }

    cout << "Yes";

    return 0;
}