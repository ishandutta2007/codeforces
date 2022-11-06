#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 1024

int n,i;
vector<int> ans;
bool ciur[maxN];

int main()
{
    cin >> n ;
    for (i = 2; i <= n; i++) {
        if (ciur[i]) continue;

        for (int aux = i; aux <= n; aux *= i) ans.pb(aux);

        for (int j = i * i; j <= n; j += i) ciur[j] = true;
    }

    cout << ans.size() << '\n';
    for (auto e : ans) cout << e << ' ';


    return 0;
}