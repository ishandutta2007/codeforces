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

    scid(a, b, c);
    heap<int> usb, ps;
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        scids(s);
        if (s == "USB") {
            usb.push(x);
        } else {
            ps.push(x);
        }
    }
    
    int ac = 0;
    lint as = 0;
    for (int i = 0; i < a; i++) {
        if (!usb.empty()) {
            ac++;
            as += usb.top();
            usb.pop();
        }
    }
    
    for (int i = 0; i < b; i++) {
        if (!ps.empty()) {
            ac++;
            as += ps.top();
            ps.pop();
        }
    }
    
    while (!ps.empty()) {
        usb.push(ps.top());
        ps.pop();
    }
    
    for (int i = 0; i < c; i++) {
        if (!usb.empty()) {
            ac++;
            as += usb.top();
            usb.pop();
        }
    }
    
    cout << ac << " " << as;
    

    return 0;
}