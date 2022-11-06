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

int n, i, a, b, c, d;
vector< pair<int, int> > v;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d;
        v.pb(mp(-(a + b + c + d), i));
    }

    sort(v.begin(), v.end());
    for (i = 0; v[i].second != 1; i++);
    cout << i + 1;


    return 0;
}