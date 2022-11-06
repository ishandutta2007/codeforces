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

const int maxN = 200011;

int n, open, act;
char s[maxN];
int times;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s", &n, s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') {
            act++;
            open++;
        } else {
            act--;
        }

        if (act < 0) {
            act = 0;
            times++;
        }
    }

    if (times <= 1 && open == n - open)
        printf("Yes");
    else 
        printf("No");

    return 0;
}