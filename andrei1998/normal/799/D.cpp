#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int NMAX = 100000 + 5;
int ans;

void backtr(int pos, int A, int B, long long int a, long long int b, const vector <int> &ext, int lst, bool type) {
    if (a >= A && b >= B) {
        ans = pos;
        return ;
    }

    if (pos == ext.size())
        return ;
    if (pos == ans - 1)
        return ;

    if (ext[pos] == lst) {
        if (a < A && type == 0)
            backtr(pos + 1, A, B, a * ext[pos], b, ext, ext[pos], 0);
        if (b < B)
            backtr(pos + 1, A, B, a, b * ext[pos], ext, ext[pos], 1);
    }
    else {
        if (a < A)
            backtr(pos + 1, A, B, a * ext[pos], b, ext, ext[pos], 0);
        if (b < B)
            backtr(pos + 1, A, B, a, b * ext[pos], ext, ext[pos], 1);
    }

}
int solve(int A, int B, int H, int W, vector <int> ext) {
    int a = 1;
    while (a * A < H)
        ++ a;
    A = a;

    int b = 1;
    while (b * B < W)
        ++ b;
    B = b;

    sort(ext.begin(), ext.end(), greater <int>());

    ans = NMAX;
    backtr(0, A, B, 1, 1, ext, 0, 0);

    if (ans == NMAX)
        return -1;
    else
        return ans;
}

int main()
{
    int A, B, H, W, N;
    cin >> H >> W >> A >> B >> N;

    vector <int> v(N);
    for (int i = 0; i < N; ++ i)
        cin >> v[i];

    int ans1 = solve(A, B, H, W, v);
    int ans2 = solve(A, B, W, H, v);

    if (ans1 == -1)
        cout << ans2 << '\n';
    else if (ans2 == -1)
        cout << ans1 << '\n';
    else
        cout << min(ans1, ans2) << '\n';
    return 0;
}