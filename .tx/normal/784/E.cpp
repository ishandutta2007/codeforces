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

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);

    int p[4];
    int x[4];
    for (int i = 0; i < 4; i++) {
        sci(x[i]);
        p[i] = i;
    }
    do {
        int a = x[p[0]];
        int b = x[p[1]];
        int c = x[p[2]];
        int d = x[p[3]];
        int i1 = a ^ b;
        int i2 = c | d;
        int i3 = b & c;
        int i4 = a ^ d;
        int i5 = i1 & i2;
        int i6 = i3 | i4;
        int i7 = i5 ^ i6;
//        if (i7 == 0) {
//            for (int i = 0; i < 4; i++) {
//                cout << p[i] << " ";
//            }
//            cout << endl;
//        }
        cout << i7;
        break;
    } while (next_permutation(p, p + 4));

    return 0;
}