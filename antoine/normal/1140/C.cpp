#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


struct DS {
    priority_queue<int, vector<int>, greater<>> pq;
    ll sum = 0;

    void insert(int x) {
        pq.push(x);
        sum += x;
    }

    void pop() {
        sum -= pq.top();
        pq.pop();
    }


    int size() {
        return (int) pq.size();
    }
};

struct X {
    int t, b;

    bool operator<(const X &other) const {
        return b > other.b;
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n, k;
    cin >> n >> k;
    vector<X> v(n);
    for (X &x : v)
        cin >> x.t >> x.b;

    sort(v.begin(), v.end());

    ll ans = 0;
    DS ds;
    for (X &x : v) {
        ds.insert(x.t);
        if (ds.size() > k)
            ds.pop();
        ans = max(ans, ds.sum * x.b);
    }
    cout << ans;
    return 0;
}