#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    long int n, ai;
    long long int score;
    bool second;
    vector<long int> a;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        a.clear();
        cin >> n;
        long int j = 0;
        for(; j < n; j ++) {
            cin >> ai;
            a.push_back(ai);
        }
        sort(a.begin(),a.end());
        second = 0;
        score = 0;
        for(j--; j >= 0; j --) {
            if(second-(a[j]%2) == 0) {
                score += a[j]*(second*2-1);
            }
            second = 1-second;
        }
        if(score == 0) {
            cout << "Tie" << endl;
            continue;
        }
        cout << (score < 0 ? "Alice" : "Bob") << endl;
    }
    return 0;
}