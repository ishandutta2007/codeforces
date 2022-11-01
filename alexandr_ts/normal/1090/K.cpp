#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 10;

char ch1[N], ch2[N];
string s[N], t[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);
    map <string, vector<int> > m;
    fr(i, n) {
        scanf("%s %s", &ch1, &ch2);
        s[i] = ch1;
        t[i] = ch2;
        //cout << s[i] << " " << t[i] << endl;
        sort(t[i].begin(), t[i].end());
        t[i].resize(unique(t[i].begin(), t[i].end()) - t[i].begin());
        vector<int> used(26, 0);
        fr(j, t[i].size())
            used[t[i][j] - 'a'] = 1;
        while (s[i].size() && used[s[i].back() - 'a'])
            s[i].pop_back();
        m[s[i] + '!' + t[i]].push_back(i);
    }

    cout << m.size() << "\n";
    for (auto& x: m) {
        cout << x.second.size() << " ";
        for (auto y: x.second)
            cout << y + 1 << " ";
        cout << "\n";
    }
}