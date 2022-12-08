#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,a;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<int> sol(n);

    for(int i = 0; i < n; i ++) {
        cin >> a;
        sol[a-1] = i+1;
    }
    for(int i = 0; i < n; i ++) {
        cout << sol[i] << " ";
    }
    return 0;
}