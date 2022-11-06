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
#define sigma 26

int n, i, j;
char s1[maxN], s2[maxN];
int cnt[33];
vector<int> ans;

void execute(int x) {
    int i, j;

    ans.pb(x);

    reverse(s1 + (n - x + 1), s1 + n + 1);
    reverse(s1 + 1, s1 + n + 1);
    reverse(s1 + 1, s1 + x + 1);
    reverse(s1 + x + 1, s1 + n + 1);

    //for (int j = 1; j <= n; j++) cerr << s1[j];
    //cerr << '\n';
}

void move_to_end(int pos) {
    execute(n - pos);
    execute(1);
    execute(n);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s\n%s", &n, s1 + 1, s2 + 1);

    for (i = 1; i <= n; i++) {
        cnt[s1[i] - 'a']++;
        cnt[s2[i] - 'a']--;
    }

    for (i = 0; i < sigma; i++) {
        if (cnt[i] != 0) {
            cout << -1;
            return 0;
        }
    }

    for (i = 1; i <= n; i++) {
        char src = s2[i];

        for (j = 1; s1[j] != src; j++);
        move_to_end(j);
    }

    for (i = 1; i <= n; i++)
        if (s1[i] != s2[i])
            cerr << "err";

    printf("%d\n", ans.size());
    for (auto e : ans) printf("%d ", e);


    return 0;
}