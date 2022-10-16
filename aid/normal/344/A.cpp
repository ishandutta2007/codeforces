#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int lastm;
    cin >> lastm;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        int nextm;
        cin >> nextm;
        if(lastm != nextm)
            ans++;
        lastm = nextm;
    }
    cout << ans << '\n';
}