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

const int maxN = 500011;

int n, m, u, pr[maxN];
char s[maxN];
int cnt[2];

void done() {
    while (cnt[0]-- > 0) printf("0");
    while (cnt[1]-- > 0) printf("1");
    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s\n", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) cnt[s[i] - '0']++;
    memset(s, 0, sizeof(s));

    scanf("%s", s + 1);
    m = strlen(s + 1);

    pr[1] = u = 0;
    for (int i = 2; i <= m; i++) {
        while (u != 0 && s[u + 1] != s[i]) 
            u = pr[u];
        if (s[u + 1] == s[i]) u++;
        pr[i] = u;
    }

    for (int i = 1; i <= m; i++) {
        int t = s[i] - '0';
        if (cnt[t] == 0) done();
        printf("%c", s[i]);
        cnt[t]--;
    }

    while(true) {
        for (int i = u + 1; i <= m; i++) {
            int t = s[i] - '0';
            if (cnt[t] == 0) done();
            printf("%c", s[i]);
            cnt[t]--;
        }
    }

    done();

    return 0;
}