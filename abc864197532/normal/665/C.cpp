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
    string s;
    cin >> s;
    s += '1';
    fop (i,1,s.length()-1) {
        if (s[i] == s[i-1]) {
            s[i] = 'a';
            while (s[i] == s[i-1] or s[i] == s[i+1]) {
                s[i]++;
            }
        }
    }
    fop (i,0,s.length()-1) cout << s[i];
    cout << endl;
}