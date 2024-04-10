#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
int x[MAXN];
long long p[MAXN];

int get(int y, int d) {
    if(!(y % d))
        return 0;
    if(!((y - 1) % d) || !((y + 1) % d))
        return 1;
    return -1;
}

long long solve1(int n, int a, int b, int div) {
    for(int i = 0; i <= n; i++)
        p[i] = INF;
    p[0] = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int need = get(x[i], div);
        if(need == -1)
            break;
        cnt += need;
        p[i + 1] = (long long)b * cnt - (long long)a * (i + 1);
    }
    cnt = 0;
    long long s = (long long)a * n, res = INF;
    for(int i = n; i > 0; i--) {
        res = min(res, p[i] + s);
        int need = get(x[i - 1], div);
        if(cnt == -1 || need == -1)
            cnt = -1;
        else
            cnt += need;
        if(cnt != -1)
            s = min(s, (long long)b * cnt + (long long)a * (i - 1));
    }
    return res;
}

long long solve(int n, int a, int b) { 
    long long res = INF;
    for(int add = -1; add <= 1; add++) {
        int y = x[0] + add;
        for(int i = 2; i * i <= y; i++)
            if(!(y % i)) {
                res = min(res, solve1(n, a, b, i));
                while(!(y % i))
                    y /= i;
            }
        if(y != 1)
            res = min(res, solve1(n, a, b, y));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    long long ans = solve(n, a, b);
    reverse(x, x + n);
    ans = min(ans, solve(n, a, b));
    cout << ans << '\n';
    return 0;
}