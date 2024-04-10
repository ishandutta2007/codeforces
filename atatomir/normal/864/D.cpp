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

#define maxN 200011

int n, i, pos;
int p[maxN], ans;
int in[maxN], out[maxN];
bool used[maxN];


int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) out[i] = 1;
    for (i = 1; i <= n; i++) {
        cin >> p[i];
        in[p[i]]++;
        out[p[i]] = 0;
    }

    for (i = 1; i <= n; i++)
        ans += max(0, in[i] - 1);

    out[n + 1] = 1111111;
    for (i = 1; i <= n; i++) {
        if (in[p[i]] == 1) continue;

        while (out[pos] == 0) pos++;
        if (pos < p[i] || used[p[i]]) {
            in[p[i]]--;
            p[i] = pos;
            pos++;
        } {
            used[p[i]] = true;
        }
    }

    cout << ans << '\n';
    for (i = 1; i <= n; i++) cout << p[i] << ' ';


    return 0;
}