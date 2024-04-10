#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 2001;
const ld EPS = 1e-8;
const ll INF = 2e9 + 10;

string s[] = {"Tetrahedron", "Cube", "Octahedron", "Dodecahedron", "Icosahedron"};
int cnt[] = {4, 6, 8, 12, 20};

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    int ans = 0;
    string s1;
    fr(i, n) {
        cin >> s1;
        fr(j, 5)
            if (s[j] == s1)
                ans += cnt[j];
    }
    cout << ans;
}