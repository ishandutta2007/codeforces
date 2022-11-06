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

template <typename T, typename Cmp = std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

pair<int, int> a[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    scids(a, b);
    multiset<char> s1, s2;
    for (int i = 0; i < n; i++) {
        s1.insert(b[i]);
        s2.insert(b[i]);
    }
    
    int a1 = 0, a2 = 0;
    for (int i = 0; i < n; i++) {
        auto it1 = s1.lower_bound(a[i]);
        if (it1 == s1.end()) {
            a1++;
            s1.erase(s1.begin());
        } else {
            s1.erase(it1);
        }
        
        auto it2 = s2.upper_bound(a[i]);
        if (it2 == s2.end()) {
            s2.erase(s2.begin());
        } else {
            a2++;
            s2.erase(it2);
        }
    }
    
    cout << a1 << "\n" << a2;
    
    return 0;
}