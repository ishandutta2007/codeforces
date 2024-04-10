#include <iostream>
using namespace std;

typedef long long ll;

ll f(int x) {
    return (ll)x * (x + 1) / 2;
}

int main() {
    ll N;
    cin >> N;
    int lo = 0, hi = (int)1e8;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (f(mid) < N) lo = mid;
        else hi = mid - 1;
    }
    
    cout << N - f(lo) << endl;
    
    return 0;
}