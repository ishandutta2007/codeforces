#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
 
 
int main () {
    int n,k,now=0;
    string s;
    cin >> n >> k >> s;
    if (s.length()==1) {
        if (k==0) cout << s << endl;
        else cout << 0 << endl;
        return 0;
    }
    if (s[0]!='1' && k>0) {
        s[0]='1';
        k--;
    }
    now=1;
    while (k>0 && now<n) {
        if (s[now]!='0') {
            k--;
            s[now]='0';
        }
        now++;
    }
    cout << s << endl;
}