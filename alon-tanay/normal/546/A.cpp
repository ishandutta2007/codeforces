#include <iostream>

using namespace std;

int main() {
    long long int n;
    int k,w;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> n >> w;
    long long int d = k*w*(w+1)/2 - n;
    cout << ((d > 0) ? d : 0);
    return 0;
}