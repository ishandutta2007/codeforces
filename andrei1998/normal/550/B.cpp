#include <iostream>
#include <algorithm>

using namespace std;

int n, l, r, x;
int v[20];

int used[20];

int ans = 0;
void backtr(int poz, int cate, int sum) {
    if (poz == (n + 1)) {
        if (cate && l <= sum && sum <= r && used[cate] - used[1] >= x)
            ++ ans;
        return ;
    }

    used[cate + 1] = v[poz];
    backtr(poz + 1, cate + 1, sum + v[poz]);

    backtr(poz + 1, cate, sum);
}

int main()
{
    cin >> n >> l >> r >> x;
    for (int i = 1; i <= n; ++ i)
        cin >> v[i];
    sort(v + 1, v + n + 1);

    backtr(1, 0, 0);

    cout << ans << '\n';
    return 0;
}