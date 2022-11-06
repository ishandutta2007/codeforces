#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 100011

int n, i, t;
char s1[maxN], s2[maxN];
char ans[maxN];

vector<int> dif;
vector<int> same;

char getDif(char a) {
    if (a != 'a') return 'a';
    return 'b';
}

char getDif2(char a, char b) {
    if (a != 'a' && b != 'a') return 'a';
    if (a != 'b' && b != 'b') return 'b';
    return 'c';
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n%s\n%s", &n, &t, s1 + 1, s2 + 1);
    for (i = 1; i <= n; i++)
        if (s1[i] == s2[i])
            same.pb(i);
        else
            dif.pb(i);

    if (dif.size() > 2 * t) {
        printf("-1");
        return 0;
    }

    if (dif.size() % 2 == 1) {
        int pos = dif[dif.size() -1];
        dif.pop_back();

        ans[pos] = getDif2(s1[pos], s2[pos]);
        t--;
        if (t < 0) {
            printf("-1");
            return 0;
        }
    }

    int dim = dif.size() / 2;
    for (i = 0; i < dif.size(); i += 2) {
        ans[ dif[i] ] = s1[ dif[i] ];
        ans[ dif[i + 1] ] = s2[ dif[i + 1] ];
    }

    t -= dim;
    while (t > 0 && same.size() > 0) {
        int pos = same[same.size() - 1];
        same.pop_back();

        ans[pos] = getDif(s1[pos]);

        t--;
    }
    for (auto who : same)
        ans[who] = s1[who];

    while (t > 0 && dif.size() > 0) {
        int pos1 = dif[ dif.size() - 1 ];
        dif.pop_back();
        int pos2 = dif[ dif.size() - 1 ];
        dif.pop_back();

        ans[pos1] = getDif2(s1[pos1], s2[pos1]);
        ans[pos2] = getDif2(s1[pos2], s2[pos2]);

        t--;
    }

    if (t > 0) {
        printf("-1");
        return 0;
    }

    for (i = 1; i <= n; i++) printf("%c", ans[i]);

    return 0;
}