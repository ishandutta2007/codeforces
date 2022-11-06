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

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

bool out[111];

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    scid(n, k);
    int i = 0;
    int rest = n;
    while (k-- > 0) {
        scid(x);
        x++;
        x %= rest;
        if (x == 0) {
            x = rest;
        }
        rest--;
        while (x > 0) {
            if (!out[i]) {
                x--;
            }
            i++;
            i %= n;
        }
        int last = (i - 1 + n) % n;
        out[last] = true;
        cout << last + 1 << " ";
    }


    return 0;
}