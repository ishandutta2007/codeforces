#include <iostream>

using namespace std;

int main() {
    long long int m, n, k;
    cin >> m >> n >> k;
    if (m%k==0&&n%k==0){
        cout << (m/k)*(n/k) << endl;
    }
    if (m%k==0&&n%k!=0){
        cout << (m/k)*((n/k)+1) << endl;
    }
    if (n%k==0&&m%k!=0){
        cout << (n/k)*((m/k)+1) << endl;
    }
    if (n%k!=0&&m%k!=0){
        cout << ((n/k)+1)*((m/k)+1) << endl;
    }



}