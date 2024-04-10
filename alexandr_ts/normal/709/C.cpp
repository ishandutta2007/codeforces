#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5;
const int M = 1e3 + 10;
const int INF = 2e9 + 1;
const ld EPS = 1e-10;
const ld PI = acos(-1);

int a[N];

int main(){
	//freopen("bacon.in", "r", stdin);
	//freopen("bacon.out", "w", stdout);
    string s;
    cin >> s;
    bool fl = false;
    fr(i, s.size())
        if (s[i] == 'a' && fl) {
            cout << s;
            return 0;
        }
        else if (s[i] == 'a' && !fl)
            continue;
        else {
            s[i]--;
            fl = true;
        }
    if (!fl)
        s[(int)s.size() - 1] = 'z';
    cout << s;
}