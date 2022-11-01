#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 3;

struct pers {
    string name;
    int reg, score;
} a[N];

bool cmp(pers a, pers b) {
    if (a.reg != b.reg)
        return a.reg < b.reg;
    else
        return a.score > b.score;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i].name >> a[i].reg >> a[i].score;
    sort(a, a + n, cmp);
    int cur = 0;
    frab(i, 1, 1 + m) {
        while (a[cur].reg < i)
            cur++;
        if (cur + 2 < n && a[cur + 1].reg == a[cur + 2].reg && a[cur + 1].score == a[cur + 2].score)
            cout << "?" << endl;
        else
            cout << a[cur].name << " " << a[cur + 1].name << endl;
    }
}