#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second

int main () {
    int n, all;
    string s;
    cin >> n >> s;
    all = n;
    for (char c = 'z'; c > 'a'; --c) {
        n = s.length();
        vector <bool> is(n, false);
        fop (i,0,n) {
            if (s[i] == c) {
                if (i + 1 < n and s[i + 1] == c - 1) {
                    is[i] = true;
                    int j = i - 1;
                    while (j >= 0 and s[j] == c) is[j--] = true;
                }
                if (i - 1 >= 0 and s[i - 1] == c - 1) {
                    is[i] = true;
                    int j = i + 1;
                    while (j < n and s[j] == c) is[j++] = true;
                }
            }
        }
        string a = "";
        fop (i,0,n) {
            if (!is[i]) {
                a += s[i];
            }
        }
        swap(a, s);
    }
    cout << all - s.length() << endl;
}