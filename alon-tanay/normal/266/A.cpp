#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, sum = 0;
    string colors;
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> colors;
    char curr = colors[0];
    for(int i = 1; i < n; i ++) {
        if(colors[i] == curr) {
            sum ++;
            continue;
        }
        curr = colors[i];
    }
    cout << sum;
    return 0;
}