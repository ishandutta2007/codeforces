#include <iostream>
using namespace std;

long long bestDiv = 0;
long long n, k;

void findBest() {
    for(long long d = 1;d*d <= n && d <= 2 * n / k / (k+1);d++) {
        if(n % d == 0) {
            if(d <= 2 * n / k / (k+1)) {
                bestDiv = max(bestDiv, d);
            }
            if((n / d) <= 2 * n / k / (k+1)) {
                bestDiv = max(bestDiv, n / d);
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    
    findBest();
    
    if(bestDiv == 0) {
        cout << -1 << endl;
        return 0;
    }
    
    long long sum = 0;
    for(int i = 1;i < k;i++) {
        cout << bestDiv * i << " ";
        sum += bestDiv * i;
    }
    
    cout << n - sum << endl;
    
    return 0;
}