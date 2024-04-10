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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i + 2 < n; i++) {
        if (a[i] < a[i + 1] + a[i + 2]) {
            cout << "YES";
            return 0;
        }
    }
    
    cout << "NO";
    
    

    return 0;
}