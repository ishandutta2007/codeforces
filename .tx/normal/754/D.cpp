#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T>
using heap = priority_queue<T, vector<T>, std::greater<T>>;

typedef long long lint;

struct C {
    int l, r, id;
};

C a[333333];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, k);
    for (int i = 0; i < n; i++) {
        sci(a[i].l, a[i].r);
        a[i].id = i;
    }
    
    sort(a, a + n, [](const C& x, const C& y) { return x.l < y.l; });
    
    heap<int> q;
    for (int i = 0; i + 1 < k; i++) {
        q.push(a[i].r);
    }
    
    int ans = 0;
    int sti = -1;
    
    for (int i = k - 1; i < n; i++) {
        q.push(a[i].r);
        while (q.top() < a[i].l || q.size() > k) {
            q.pop();
        }
        if (q.size() < k) {
            continue;
        }
        
        int x = q.top() - a[i].l + 1;
        if (x > ans) {
            ans = x;
            sti = i;
        }
    }
    
    cout << ans << "\n";
    if (ans == 0) {
        for (int i = 0; i < k; i++) {
            cout << i + 1 << " ";
        }
        return 0;
    }
    
    int out = 0;
    for (int i = 0; out < k && i <= sti; i++) {
        if (a[i].r - a[sti].l + 1 >= ans) {
            cout << a[i].id + 1 << " ";
            out++;
        }
    }
    

    return 0;
}