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

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

int t, a, b, c;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &t);
    for (int ti = 1; ti <= t; ti++) {
        scanf("%d%d%d", &a, &b, &c);

        a += c;
        if (a <= b) {
            printf("0\n");
            continue;
        }

        a = max(a - b - 1, 0) / 2;
        a = min(a + 1, c + 1);
        printf("%d\n", a);
    }


    return 0;
}