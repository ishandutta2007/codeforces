#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>
 
int main () {
	int t;
	cin >> t;
    while (t--) {
        int n;
        string s1, s2;
        cin >> n >> s1 >> s2;
        int a[26];
        fop (i,0,26) a[i] = 0;
        int cnt1=0, cnt2=0;
        fop (i,0,n) {
            cnt1 += a[s1[i]-'a'];
            fop (j,s1[i]-'a',26) {
                a[j]++;
            }
        }
        fop (i,0,26) a[i] = 0;
        fop (i,0,n) {
            cnt2 += a[s2[i]-'a'];
            fop (j,s2[i]-'a',26) {
                a[j]++;
            }
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool is = false;
        if (s1 == s2) {
            fop (i,0,n-1) {
                if (s1[i] == s1[i+1]) is = true;
            }
        }
        if (is or (s1 == s2 and cnt1 % 2 == cnt2 % 2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}