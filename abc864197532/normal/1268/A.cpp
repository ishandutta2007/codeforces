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
    int n,k;
    string s;
    cin >> n >> k >> s;
    int a[k];
    fop (i,0,k) {
        a[i] = s[i] - '0';
    }
    bool is = true;
    fop (i,k,n) {
        if (s[i] - '0' < a[i % k]) {
        	break;
        } else if (s[i] - '0' > a[i % k]) {
            is = false;
        }
    }
    if (!is) {
        a[k-1]++;
        int now = k - 1;
        while (a[now] == 10) {
            a[now] = 0;
            now--;
            a[now]++;
        }
    }
    cout << n << endl;
    fop (i,0,n) cout << a[i%k];
    cout << endl;
}