#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<long int> input;
    int t;
    long int n, a, sol;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        input.clear();
        cin >> n;
        for(int j = 0; j < n; j ++) {
            cin >> a;
            input.push_back(a);
        }
        sol = -1;
        sort(input.begin(), input.end());
        for(int j = 0; j < n; j ++) {
            if(input[j] <= j+1) {
                sol = j;
            }
        }
        cout << sol+2 << endl;
    }
    return 0;
}