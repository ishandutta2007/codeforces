#include <iostream>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7, MAXA = 1000 * 1000 + 5;

long long ft[MAXA];

long long getsum(int i) {
    long long sum = 0;
    while(i >= 0) {
        sum = (sum + ft[i]) % MOD;
        i = (i & (i + 1)) - 1;
    }
    return sum;
}

void update(int i, int x) {
    while(i < MAXA) {
        ft[i] += x;
        i |= i + 1;
    }
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        update(a, (getsum(a) * (a - 1) + getsum(a - 1) + a) % MOD);
    }
    cout << getsum(MAXA - 1) << '\n';
}