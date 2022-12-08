#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double a,b;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    cout << ceil(log(b/a)*2.466303462376431686007+0.001);
    return 0;
}