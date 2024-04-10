#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

int main () {
    int n, m, tmp;
    cin >> n >> m;
    set <int> ans;
    set <int> input;
    lli anss = 0;
    queue <pii> q1;
    fop (i,0,n) cin >> tmp, q1.push({tmp,0}), input.insert(tmp);
    while (ans.size() < m) {
        int aa, bb;
        tie(aa, bb) = q1.front();
        q1.pop();
        if (!(ans.count(aa+1) or input.count(aa+1))) {
            ans.insert(aa+1);
            q1.push({aa+1, bb+1});
            anss += (bb + 1);
        }
        if (ans.size() == m) break;
        if (!(ans.count(aa-1) or input.count(aa-1))) {
            ans.insert(aa-1);
            q1.push({aa-1, bb+1});
            anss += (bb + 1);
        }
    }
    cout << anss << endl;
    for (int a : ans) cout << a << ' ';
    cout << endl;
}