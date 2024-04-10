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
    int n, m, a, b;
    cin >> n >> m;
    set <int> nums[n];
    fop (i,0,m) {
        cin >> a >> b;
        a--; b--;
        nums[a].insert(b);
        nums[b].insert(a);
    }
    int now = 0;
    while (true) {
        bool is = true;
        set <int> aa;
        fop (i,0,n) {
            if (nums[i].size() == 1) aa.insert(i), is = false;
        }
        if (is) break;
        fop (i,0,n) {
            if (aa.count(i)) {
                nums[i].clear();
                continue;
            }
            for (int j : aa) {
                nums[i].erase(j);
            }
        }
        now++;
    }
    cout << now << endl;
}