#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long int n, a;
    vector<long int> p;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> a;
        p.push_back(a);
    }
    cout << (n-1)/2 << endl;
    sort(p.begin(), p.end());
    for(int i = 0; i < n/2; i ++) {
        cout << p[n-i-1] << " " << p[i] << " ";
    }
    if(n%2) {
        cout << p[n/2];
    }
    return 0;
}