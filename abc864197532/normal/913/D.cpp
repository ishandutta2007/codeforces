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
const int N = 200000;
int a[N], t[N];

struct cmp {
    bool operator () (int i, int j) {
        return a[i] > a[j];
    }
};

struct cmp2 {
    bool operator () (int i, int j) {
        return t[i] > t[j];
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, limit;
    cin >> n >> limit;
    fop (i,0,n) cin >> a[i] >> t[i];
    priority_queue <int, vector <int>, cmp> pq;
    int index[n];
    iota(index, index + n, 0);
    sort(index, index + n, [](int i, int j) {
        return t[i] < t[j];
    });
    int all = 0, ans = 0;
    fop (i,0,n) {
        bool move = false;
        if (all + t[index[i]] <= limit) {
            pq.push(index[i]);
            all += t[index[i]];
            move = true;
        }
        while (pq.size() and a[pq.top()] < pq.size()) {
            all -= t[pq.top()];
            pq.pop();
            move = true;
        }
        ans = max(ans, int(pq.size()));
        if (!move) break;
    }
    cout << ans << endl << ans << endl;
    priority_queue <int, vector <int>, cmp2> pq2;
    fop (i,0,n) {
        if (a[i] >= ans) pq2.push(i);
    }
    int count = 0;
    while (count < ans) {
        cout << pq2.top() + 1 << ' ';
        count++;
        pq2.pop();
    }
}