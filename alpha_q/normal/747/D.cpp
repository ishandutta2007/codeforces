#include <bits/stdc++.h>
 
using namespace std;

const int N = 2e5 + 10;

int n, k, a[N], c[N], neg = 0;
vector <int> v;

int main (int argc, char const *argv[]) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        if (a[i] < 0) ++neg;
        if (a[i] == 0) a[i] = 1;
    }
    if (neg > k) {
        puts("-1");
        return 0;
    }
    if (neg == 0) {
        puts("0");
        return 0;
    }
    int ii = 1, tot = 0;
    while (ii <= n and a[ii] >= 0) ++ii;
    for (int j = ii; j <= n; ++j) {
        int cnt = 1, l = j + 1;
        while (l <= n and a[l] * a[l - 1] >= 0) {
            // cout<<"yo\n";
            ++l, ++cnt;
        }
        c[++tot] = cnt;
        j = l - 1; 
    }
    // for (int i = 1; i <= tot; ++i) {
    //     cout << c[i] << " ";
    // } cout << endl;
    int rem = k - neg;
    int move = 1;
    for (int i = 2; i < tot; i += 2) {
        v.push_back(c[i]);
        move += 2;
    }
    sort(v.begin(), v.end());
    if (tot & 1) {
        for (int i = 0; i < (int) v.size(); ++i) {
            if (rem - v[i] >= 0) {
                rem -= v[i];
                move -= 2;
            } else {
                break;
            }
        }
        printf("%d\n", move);
    } else {
        int nmove = 10 * move;
        // not changing at last
        if (rem >= c[tot]) {
            nmove = move;
            int nrem = rem - c[tot];
            for (int i = 0; i < (int) v.size(); ++i) {
                if (nrem - v[i] >= 0) {
                    nrem -= v[i];
                    nmove -= 2;
                } else {
                    break;
                }
            }
        }
        ++move;
        for (int i = 0; i < (int) v.size(); ++i) {
            if (rem - v[i] >= 0) {
                rem -= v[i];
                move -= 2;
            } else {
                break;
            }
        }
        move = min(move, nmove);
        printf("%d\n", move);
    }
    return 0;
}