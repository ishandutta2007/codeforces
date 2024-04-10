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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    string s[n];
    map <string,int> m1;
    fop (i,0,n) {
        cin >> s[i];
        if (m1.count(s[i])) m1[s[i]]++;
        else m1[s[i]] = 1;
    }
    int ans = 0;
    fop (i,0,n) {
        fop (j,i+1,n) {
            string ss = "";
            fop (ii,0,k) {
                if (s[i][ii] == s[j][ii]) ss += s[i][ii];
                else ss += 'S' + 'E' - s[i][ii] + 'T' - s[j][ii];
            }
            ans += m1[ss];
        }
    }
    cout << ans / 3 << endl;
}