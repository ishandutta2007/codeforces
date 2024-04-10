#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        int p = 60;
        while(p >= 0 && (a & (1ll << p)) == (b & (1ll << p)))
            p--;
        if(p >= 0) {
            a |= (1ll << p) - 1;
            if((a | (1ll << p)) <= b)
                a |= (1ll << p);
        }
        cout << a << '\n';
    }
    return 0;
}