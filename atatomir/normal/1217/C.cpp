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

int t, n, before, act, answer;
char s[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n", &t);
    for (int ti = 1; ti <= t; ti++) {
        scanf("%s\n", s + 1);
        n = strlen(s + 1);

        before = answer = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') {
                before++;
                continue;
            }

            act = 0;
            for (int j = 0; j < 20 && i + j <= n; j++) {
                act = (act << 1) | (s[i + j] - '0');
                if (act >= j + 1 && act <= j + 1 + before) 
                    answer++;
            }

            before = 0;
        }

        printf("%d\n", answer);
    }


    return 0;
}