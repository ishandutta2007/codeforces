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
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector <int> aa(3, 0);
    int now = 0;
    bool is = true;
    fop (i,0,s.length()) {
        if (s[i] == 'b') now = max(now, 1);
        if (s[i] == 'c') now = max(now, 2);
        if (s[i] != 'a' + now) is = false;
        aa[now]++;
    }
    is &= (aa[0] == aa[2] or aa[1] == aa[2]);
    is &= (!(aa[0] == 0 or aa[1] == 0));
    cout << (is ? "YES" : "NO") << endl;
}