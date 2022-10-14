#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>


int main () {
    int n, tmp;
    cin >> n;
    set <int> aa, bb;
    vector <int> nums;
    nums.pb(0);
    fop (i,0,n) {
        cin >> tmp;
        if (tmp > 0) {
            if (aa.count(tmp) or bb.count(tmp)) {
                cout << -1 << endl;
                return 0;
            }
            aa.insert(tmp);
            bb.insert(tmp);
        } else {
            if (!aa.count(-tmp)) {
                cout << -1 << endl;
                return 0;
            }
            aa.erase(-tmp);
        } if (!aa.size()) {
            nums.pb(i + 1);
            bb.clear();
        }
    }
    if (aa.size()) {
        cout << -1 << endl;
        return 0;
    }
    cout << nums.size() - 1 << endl;
    fop (i,1,nums.size()) cout << nums[i] - nums[i-1] << " \n"[i == nums.size() - 1];
}