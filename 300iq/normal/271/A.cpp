#include <bits/stdc++.h>
//#define int long long
#define mp make_pair

using namespace std;

bool test(int n) {
    int a = n % 10;
    int b = n / 10 % 10;
    int c = n / 10 / 10 % 10;
    int d = n / 10/ 10 / 10 % 10;
    if(a != b && a != c && a != d && b != c && b != d && c != d) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    n++;
    while(!test(n)) {
        n++;
    }
    cout << n;
}