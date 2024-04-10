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

#define maxN 22

int n, i;
char s[maxN];
vector<int> ord;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s", &n, s + 1);
    for (i = 1; i <= n; i++) {
        if (s[i] <= '1') continue;
        if (s[i] == '2') {
            ord.pb(2);
        }
        if (s[i] == '3') {
            ord.pb(3);
        }
        if (s[i] == '4') {
            ord.pb(2);
            ord.pb(2);
            ord.pb(3);
        }
        if (s[i] == '5') {
            ord.pb(5);
        }
        if (s[i] == '6') {
            ord.pb(5);
            ord.pb(3);
        }
        if (s[i] == '7') {
            ord.pb(7);
        }
        if (s[i] == '8') {
            ord.pb(7);
            ord.pb(2);
            ord.pb(2);
            ord.pb(2);
        }
        if (s[i] == '9') {
            ord.pb(7);
            ord.pb(3);
            ord.pb(3);
            ord.pb(2);
        }
    }

    sort(ord.begin(), ord.end());
    reverse(ord.begin(), ord.end());

    for (auto e : ord) printf("%d", e);


    return 0;
}