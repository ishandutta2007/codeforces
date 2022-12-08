#include <iostream>

using namespace std;

int main() {
    int n;
    bool hate = true;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n-1; i ++) {
        cout << (hate ? "I hate that " : "I love that ");
        hate = !hate;
    }
    cout << (hate ? "I hate it" : "I love it");
    return 0;
}