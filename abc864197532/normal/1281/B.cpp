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


int main () {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        vector <bool> now(26,false);
        vector <bool> is(s1.length(),false);
        FOP (i,s1.length(),0) {
            if (now[s1[i]-'A']) {
                is[i] = true;
            }
            fop (j,s1[i]-'A'+1,26) {
                now[j] = true;
            }
        }
        fop (i,0,s1.length()) {
            if (is[i]) {
                char c = 'Z';
                int a;
                fop (j,i+1,s1.length()) {
                    if (c >= s1[j]) {
                        c = s1[j];
                        a = j;
                    }
                }
                swap(s1[i], s1[a]);
                break;
            }
        }
        if (s1 < s2) cout << s1 << endl;
        else cout << "---" << endl;
    }
}