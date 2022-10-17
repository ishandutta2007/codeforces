#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) {
    return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "{"; for (int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "}"; }
int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int res; cin >> res;
    return res;
}
int main() {
    int n; cin >> n;
    vector<int> ans(n + 1);
    vector<int> bad;
    for (int i = 1; i <= n; i++) bad.push_back(i);
    while (bad.size() > 1) {
        int two = bad.back();
        bad.pop_back();
        int one = bad.back();
        bad.pop_back();
        int a = ask(one, two);
        int b = ask(two, one);
        if (a > b) {
            ans[one] = a;
            bad.push_back(two);
        } else {
            ans[two] = b;
            bad.push_back(one);
        }
    }
    vector<int> used(n + 1);
    for (int i = 1; i <= n; i++) used[ans[i]] = 1;
    int val = -1;
    for (int i = 1; i <= n; i++) {
        if (used[i] == 0) val = i;
    }
    ans[bad[0]] = val;
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}