#include <iostream>

using namespace std;

const int MAXA = 1000 * 1000 + 5;
int s[MAXA], n, k;

bool check(int p) {
    for(int i = 0; i < MAXA; i += p) {
        int l = i? i + k : 0, r = min(i + p - 1, MAXA - 1);
        if(l < r && s[r] - s[l])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s[a]++;
    }
    for(int i = 1; i < MAXA; i++)
        s[i] += s[i - 1];
    for(int i = MAXA; i > 0; i--)
        if(check(i)) {
            cout << i << '\n';
            return 0;
        }
    return 0;
}