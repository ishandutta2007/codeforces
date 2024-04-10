#include <iostream>

using namespace std;

int main() {
    int n, k, k_score, score, sum = 0;
    bool passed = false;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i ++) {
        cin >> score;
        if(passed || score < 1) {
            continue;
        }
        if(i < k-1) {
            sum ++;
            continue;
        }
        if(i == k-1) {
            k_score = score;
            sum ++;
            continue;
        }
        if(score < k_score) {
            passed = true;
            continue;
        }
        sum ++;
    }
    cout << sum;
    return 0;
}