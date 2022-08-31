#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define endl '\n'
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    forn (_, n) {
        cin >> s;
        int len = s.size() - 4;
        int t = atoi(s.substr(4).c_str());
        int k = 10;
        int wow = 0;
        for (int p = 1; p < len; p++) {
            wow += k;
            k *= 10;
        }
        while (t < 1989 + wow) {
            t += k;
        }
        cout << t << endl;
    }
}