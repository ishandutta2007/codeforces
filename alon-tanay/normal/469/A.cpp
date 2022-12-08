#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> a;
    vector<bool> stuck(n, true);
    for(int i = 0; i < a; i ++) {
        cin >> b;
        stuck[b-1] = false;
    }
    cin >> a;
    for(int i = 0; i < a; i ++) {
        cin >> b;
        stuck[b-1] = false;
    }
    for(int i = 0; i < n; i ++) {
        if(stuck[i]) {
            cout << "Oh, my keyboard!";
            return 0;
        }
    }
    cout << "I become the guy.";
    return 0;
}