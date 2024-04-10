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

bool was[26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scids(s);
    for (char c : s) {
        c -= 'a';
        for (int i = 0; i < c; i++) {
            if (!was[i]) {
                cout << "NO";
                return 0;
            }
        }
        was[c] = true;
    }
    
    cout << "YES";

    return 0;
}