#include <iostream>
#include <map>

using namespace std;

int main() {
    int t;
    long int n, currMin, a, last_a;
    map<long int, long int> counts;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        counts.clear();
        cin >> n;
        cin >> last_a;
        counts[last_a] = 1;
        for(long int j = 1; j < n; j ++) {
            cin >> a;
            if(a == last_a) {
                if(j == n-1) {
                    counts[a] --;
                }
                continue;
            }
            if(counts.find(a) == counts.end()) {
                counts[a] = 2;
            } else {
                counts[a] ++;
            }
            if(j == n-1) {
                counts[a] --;
            }
            last_a = a;
        }
        currMin = counts[a];
        for(auto it = counts.begin(); it != counts.end(); ++it) {
            if((it->second) < currMin) {
                currMin = (it->second);
            }
        }
        cout << currMin << endl;
    }
    return 0;
}