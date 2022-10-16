#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
int p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    string s;
    cin >> n >> k >> s;
    if(k == 1)
        cout << '1';
    else
        cout << '0';
    for(int i = 1; i < n; i++) {
        p[i] = p[i - 1];
        while(p[i] > 0 && s[i] != s[p[i]])
            p[i] = p[p[i] - 1];
        if(s[i] == s[p[i]])
            p[i]++;
        int len = i + 1, x = len - p[i], y = len / ((long long)x * k);
        if((long long)x * k * y <= len && len <= (long long)x * (k + 1) * y)
            cout << '1';
        else
            cout << '0';
    }
    cout << '\n';
    return 0;
}