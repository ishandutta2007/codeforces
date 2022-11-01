#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e4 + 1;
const int M = 1e7 + 1;;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

string a[N];

bool check(string s1, string s2, int b, int c) {
    int rb = 0, rc = 0;
    fr(i, 4)
        fr(j, 4)
            if (s1[i] == s2[j])
                if (i == j)
                    rb++;
                else
                    rc++;
    return rb == b && rc == c;
}

int main() {
    //freopen("a.in", "r", stdin);
    srand(1);
    ios_base::sync_with_stdio(false);
    set <string> s;
    fr(i1, 10)
        fr(i2, 10)
            fr(i3, 10)
                fr(i4, 10) {
                    if (!(i1 != i2 && i1 != i3 && i1 != i4 &&
                        i2 != i3 && i2 != i4 && i3 != i4))
                        continue;
                    string cur;
                    cur += ('0' + i1);
                    cur += ('0' + i2);
                    cur += ('0' + i3);
                    cur += ('0' + i4);
                    s.insert(cur);
                }
    while (true) {
        int x = rand() % (s.size());
        auto cur = s.begin();
        fr(i, x)
            cur++;
        string st = *cur;
        cout << st << endl;
        int bulls, cows;
        cin >> bulls >> cows;
        if (bulls == 4)
            break;
        set <string> s2;
        for (auto it: s)
            if (check(st, it, bulls, cows))
                s2.insert(it);
        s = s2;
        assert(s.size() > 0);
    }
}