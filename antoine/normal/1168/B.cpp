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

    string s;
    cin >> s;


    ll ans = 0;
    const int n = (int)s.size();
    for(int i = 0, j = 0; i < n; ++i) {
        while(j < n && !f(s.begin() + i, s.begin() + j))
            ++j;
        if(j >= n)
            break;
        ans += n-j;
    }
    cout << ans;
    return 0;
}