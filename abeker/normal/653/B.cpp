#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int MAXN = 10;
const int MAXQ = 40;

int N, Q;
string b[MAXQ];
int who[MAXN][MAXN];

void load() {
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < Q; i++) {
        string a;
        cin >> a >> b[i];
        who[a[0] - 'a'][a[1] - 'a'] = i + 1;
    }
}

bool check(string s) {
    while (s.size() > 1) {
        int idx = who[s[0] - 'a'][s[1] - 'a'];
        if (!idx) return false;
        s = b[idx - 1] + s.substr(2, (int)s.size() - 2);
    }
    return s == "a";
}

int solve(string s) {
    if (s.size() == N) return check(s);
    int res = 0;
    for (int i = 0; i < 6; i++)
        res += solve(s + (char)('a' + i));
    return res;
}

int main() {
    load();
    printf("%d\n", solve(""));
    return 0;
}