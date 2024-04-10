#include <bits/stdc++.h>
using namespace std;
char words[2][100];
int num[200];
bool solve() {
    scanf(" %s %s", words[0], words[1]);
    int n = strlen(words[0]);
    int m = strlen(words[1]);

    fill_n(num, 200, 0);
    for (int i = 0; i < m; i++) num[words[1][i]]++;

    vector<char> w;
    for (int i = n-1; i >= 0; i--) {
        if (num[words[0][i]]) {
            num[words[0][i]]--;
            w.push_back(words[0][i]);
        }
    }
    reverse(w.begin(), w.end());
    if (w.size() != m) return false;
    for (int i = 0; i < m; i++) {
        if (w[i] != words[1][i]) return false;
    }
    return true;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        if (solve()) printf("YES\n");
        else printf("NO\n");
    }
}