#include <iostream>

using namespace std;

int main() {
    int n,a,b,max = 0; 
    int curr = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a >> b;
        curr += b - a;
        if(curr > max) {
            max = curr;
        }
    }
    
    cout << max;
    return 0;
}