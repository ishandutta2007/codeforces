#include <bits/stdc++.h>

using namespace std;

#define M 200200
#define long long long
#define mod 1000000007ll

string s, t;
int k, p[M], n, sum[M], sum2[M], d[M];

void cmp() {
    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            ++j;
        p[i] = j;
    }
}

void rundin() {
    int last = -1;
    for (int i = k + 1; i < n; ++i) {
        d[i] = d[i - 1];
        if (p[i] >= k)
            last = i - k;
        if (last != -1)
            d[i] += sum[last] + (last - k + 1);
        d[i] %= mod;
        sum[i] = (sum[i - 1] + d[i]) % mod;
        //cerr << d[i] << " ";
    }
    //cerr << "\n";
}

int main() {
    cin >> s >> t;
    s = t + "#" + s;
    k = t.length();
    n = s.length();

    cmp();
    rundin();
    cout << d[n - 1] << "\n";

    return 0;
}