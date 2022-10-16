#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int b, d;
    cin >> b >> d;
    string a, c;
    cin >> a >> c;
    vector<int> v(c.length()), p(c.length());
    for(size_t i = 0; i < c.length(); i++) {
        int q = i;
        for(size_t j = 0; j < a.length(); j++)
            if(a[j] == c[q]) {
                q++;
                if(q == c.length()) {
                    v[i]++;
                    q = 0;
                }
            }
        p[i] = q;
    }
    int ans = 0, q = 0;
    for(int i = 0; i < b; i++) {
        ans += v[q];
        q = p[q];
    }
    ans /= d;
    cout << ans << '\n';
}