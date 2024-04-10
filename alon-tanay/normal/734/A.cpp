#include <iostream>
#include <string>

using namespace std;

int main() {
    long int n;
    string res;
    signed long int sol = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> res;
    for(int i = 0; i < n; i ++) {
        sol += ((res[i] == 'A') ? 1 : -1);
    }
    if(sol > 0) {
        cout << "Anton";
        return 0;
    }
    if(sol < 0) {
        cout << "Danik";
        return 0;
    }
    cout << "Friendship";
    return 0;
}