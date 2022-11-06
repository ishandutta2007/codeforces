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

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    multiset<char> s;
    scids(ts);
    int n = ts.length();
    for (char c : ts) {
        s.insert(c);
    }

    vector<char> t, u;

    int i = 0;
    while (!s.empty() || !t.empty()) {
        if (t.empty() || (!s.empty() && *s.begin() < t.back())) {
            t.push_back(ts[i]);
            s.erase(s.find(ts[i]));
            i++;
        } else {
            u.push_back(t.back());
            t.pop_back();
        }
    }

    for (char c : u) {
        cout << c;
    }


    return 0;
}