#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
int a[200000];


int main () {
    int n;
    cin >> n;
    fop (i,0,n) cin >> a[i];
    queue <int> q;
    int ans[n];
    set <int> s[n];
    bool vi[n];
    fop (i,0,n) ans[i] = -1, vi[i] = false;
    fop (i,0,n) {
        if (i + a[i] < n) {
            if ((a[i] + a[i+a[i]]) & 1) {
                q.push(i);
                ans[i] = 1;
            } else {
                s[i+a[i]].insert(i);
            }
        } if (i - a[i] >= 0) {
            if ((a[i] + a[i-a[i]]) & 1) {
                q.push(i);
                ans[i] = 1;
            } else {
                s[i-a[i]].insert(i);
            }
        }
    }
    while (q.size()) {
        int a = q.front();
        q.pop();
        if (vi[a]) continue;
        vi[a] = true;
        for (int i : s[a]) {
            if (ans[i] == -1) {
                ans[i] = ans[a] + 1;
                q.push(i);
            }
        }
    }
    fop (i,0,n) cout << ans[i] << " \n"[i == n - 1];
}