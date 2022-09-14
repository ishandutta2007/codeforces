#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

class BinaryIndexedTree {
public:
    BinaryIndexedTree() {}
    BinaryIndexedTree(int n) {
        n_ = n;
        arr_.resize(n_);
    }
    
    void update(int x, long long val) {
        if (x < 0 || x >= n_ )
            return;
        for (int i = x ; i < n_; i = i | (i + 1))
            arr_[i] += val;
    }
    
    long long getSum(int x) {
        if (x < 0 || x >= n_)
            return 0;
        long long ans = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            ans += arr_[i];
        return ans;
    }
private:
    int n_;
    vector< long long > arr_;
};



int main() {
    int n, k, q;
    long long a, b;
    cin >> n >> k >> a >> b >> q;
    BinaryIndexedTree bitree1(n), bitree2(n);
    vector<long long> p(n);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int pos;
            long long val;
            cin >> pos >> val;
            pos--;
            long long prev = p[pos];
            p[pos] += val;
            bitree1.update(pos, min(p[pos], b) - min(prev, b));
            bitree2.update(n - pos - 1, min(p[pos], a) - min(prev, a));
        }
        else {
            int pos;
            cin >> pos;
            pos--;
            long long ans = 0;
            ans += bitree1.getSum(pos - 1);
            ans += bitree2.getSum(n - (pos + k) - 1);
            cout << ans << endl;
        }
    }
    return 0;
}