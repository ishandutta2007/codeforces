#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;

// at most 1 group can have sz > 1
// if a group has sz > 1 then it must form a tree
// at most 1 below

int f(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x >>= 1;
    }
    return cnt;
}

int f(vector<int> v) {
    if(v.size() <= 2)
        return v.size();

    map<int, vector<int>> mp;
    for (int x : v)
        mp[f(x)].push_back(x);

    int ans = (int) mp.size();


    int cntBefore = 0, cntAfter = (int) mp.size() - 1;
    for (auto &&e : mp) {
        vector<int> &u = e.second;
        if (e.first) {
            for (int &x : u)
                x ^= 1 << (e.first - 1);
        }
        ans = max(ans, f(u) + min(cntBefore, 1) + cntAfter);
        cntBefore++;
        cntAfter--;
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a)
        cin >> x;
    cout << n - f(a);

    return 0;
}