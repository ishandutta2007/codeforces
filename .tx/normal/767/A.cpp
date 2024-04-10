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
using heap = priority_queue<T, std::vector<T>, std::greater<T>>;

typedef long long lint;

int a[111111];
bool was[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    int x = n;
    for (int i = 0; i < n; i++) {
        scid(y);
        was[y] = true;
        while (was[x]) {
            cout << x << " ";
            x--;
        }
        cout << "\n";
    }
    

    return 0;
}