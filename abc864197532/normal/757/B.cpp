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
    int n, tmp;
    cin >> n;
    int count[100087];
    fop (i,0,100087) count[i] = 0;
    fop (i,0,n) {
        cin >> tmp;
        int k = tmp;
        for (int i = 2; i * i <= tmp; ++i) {
            if (k % i) continue;
            count[i]++;
            while (k % i == 0) k /= i;
        }
        if (k > 1) count[k]++;
    }
    int ans = 1;
    fop (i,2,100087) {
        ans = max(ans, count[i]);
    }
    cout << ans << endl;
}