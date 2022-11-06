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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    vector<int> ans;
    for (int i = 1; ; i++) {
        if (n - i <= i) {
            ans.push_back(n);
            break;
        }
        ans.push_back(i);
        n -= i;
    }
    
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}