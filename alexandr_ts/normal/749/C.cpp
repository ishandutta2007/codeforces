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


int main() {
    //freopen("a.in", "r", stdin);
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> v1, v2;
    fr(i, n)
        if (s[i] == 'D')
            v1.pb(i);
        else
            v2.pb(i);
    int s1 = v1.size(), s2 = v2.size();
    int c1 = 0, c2 = 0;
    while (true) {
        fr(i, n)
            if (s[i] == '0')
                continue;
            else if (s[i] == 'D')
                if (c2) {
                    c2--, s[i] = '0';
                    s1--;
                }
                else {
                    c1++;
                }
            else if (s[i] == 'R')
                if (c1) {
                    c1--, s[i] = '0';
                    s2--;
                }
                else {
                    c2++;
                }
        if (!s1 || !s2)
            break;
    }
    if (s1)
        cout << "D";
    else
        cout << "R";

}