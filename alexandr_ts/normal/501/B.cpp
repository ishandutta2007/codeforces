#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef unsigned long long ll;

const int N = 1e2 + 10;
const int INF = 2e9;
const int ALPH = 300;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    string s, t;
    map <string, string> m;
    fr(i, n) {
        cin >> s >> t;
        if (s == t) continue;
        if (m.count(s)) {
            m[t] = m[s];
            m.erase(m.find(s));//[s] = "a";
        }
        else
            m[t] = s;
    }
    cout << m.size() << endl;
    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->second << " " << it->first << endl;

}