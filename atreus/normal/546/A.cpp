#include <iostream>

using namespace std;

int main ()

{
    int k, n, w, b, total = 0, z;
    cin >> k >> n >> w;
    for (int b = k; k <= w*b; k += b){
        total += k;
    }
    if(total >= n){
        z = total - n;
        cout << z << endl;
    }
    else{
        cout << 0 << endl;
    }
}