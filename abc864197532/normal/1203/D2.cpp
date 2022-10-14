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
    string s1, s2;
    cin >> s1 >> s2;
    int now = 0, ans = 0;
    int n1 = int(s1.size()), n2 = int(s2.size());
    int l[n2+1], r[n2+1];
    fop (i,0,n1) {
        if (s1[i] == s2[now]) {
            l[now] = i;
            now++;
        }
    }
    now = n2 - 1;
    FOP (i,n1,0) {
        if (s1[i] == s2[now]) {
            r[now] = i;
            now--;
        }
    }
    ans = max(n1 - 1 - l[n2-1], r[0]);
    fop (i,0,n2-1) {
        ans = max(ans, r[i+1] - l[i] - 1);
    }
    cout << ans << endl;
}