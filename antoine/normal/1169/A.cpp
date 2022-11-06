#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

bool f(string::iterator first, string::iterator last) {
    for(string::iterator it = first; it <= last; ++it)
        for(size_t diff = min(it-first, last - it); diff >= 1; --diff)
            if(*it == *(it-diff) && *it == *(it+diff))
                return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n,a,b,x,y;
    cin >> n>>a>>x>>b>>y;

    --a, --b, --x, --y;

    for(;;) {
        if(a==b) {
            cout << "YES";
            return 0;
        }
        if(a == x || b == y)
            break;
        a += 1;
        b += n -1;
        a %= n;
        b %= n;
    }
    cout << "NO";
    return 0;
}