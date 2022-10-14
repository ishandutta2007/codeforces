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
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int i = 0, j = 0;
        while (i < t.length() and t[i] == '0') i++;
        j = i;
        while (j < s.length() and s[j] == '0') j++;
        cout << j - i << endl;
    }
}