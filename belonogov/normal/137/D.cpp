#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
const int inf = 1e8;
string s;
string sr;
string s1;
int a[502][502];
int b[502][502];
int p[502][502];

int f(int l, int r){
    int ans = 0;
    for (int i = l; i <= r; i++)
        if (s[i] != s[r - i + l])
            ans++;
    return ans / 2;
}
void f2(int d, int k){
    int i, ans = inf, r = -1;
    if (k == 0){
        b[d][k + 1] = a[0][d];
        p[d][k + 1] = -1;
        return;
    }
    for (i = 0; i < d; i++)
        if (ans > b[i][k] + a[i + 1][d]){
            ans = b[i][k] + a[i + 1][d];
            r = i;
        }
    b[d][k + 1] = ans;
    p[d][k + 1] = r;
}

void f3(int l, int r){
    s1 = "";
    for (int i = l; i <= r; i++)
        s1 += s[i];
    for (int i = 0; i <= (r - l) / 2; i++)
        s1[i] = s1[r - l - i];
}

int main()
{
   // freopen("in", "r", stdin);
   // freopen("out", "w", stdout);
    int k, n, i, j, uk, d, x, n1;
    cin >> s;
    scanf("%d", &k);
    n = s.length();
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
            a[i][j] = f(i, j);
    for (i = 0; i < n; i++)
        for (j = 1; j <= k; j++)
            f2(i, j - 1);
    uk = 1;
    for (i = 1; i <= k; i++)
        if (b[n - 1][i] < b[n - 1][uk])
            uk = i;
    printf("%d\n", b[n - 1][uk]);
    sr = "";
    d = n - 1;
    while (d != -1){
        x = p[d][uk];
        f3(x + 1, d);
        sr = "+" + s1 + sr;
        d = x;
        uk--;
    }
    n1 = sr.length();
    for (i = 1; i < n1; i++)
        cout << sr[i];
    return 0;
}