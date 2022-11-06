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

int cnt(string& s) {
    int res = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'K' && s[i - 1] == 'V') {
            res++;
        }
    }
    return res;
}

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scids(s);
    int ans = cnt(s);
    for (int i = 0; i < s.size(); i++) {
        s[i] = s[i] == 'V' ? 'K' : 'V';
        ans = max(ans, cnt(s));
        s[i] = s[i] == 'V' ? 'K' : 'V';
    }

    cout << ans;


    return 0;
}