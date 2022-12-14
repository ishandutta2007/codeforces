#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int power(int n){
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return power(n - 1) * 2;
    return power(n / 2) * power(n / 2);
}
int main(){
    int n, k;
    cin >> n;
    for (int i = 0; i <= 100; i++){
        if (5 * power(i) > n){
            k = power(i);
            break;
        }
        n -= 5 * power(i);
    }
    if (n % k == 0){
        if (n / k == 1)
            cout << "Sheldon" << endl;
        else if (n / k == 2)
            cout << "Leonard" << endl;
        else if (n  / k == 3)
            cout << "Penny" << endl;
        else if (n  / k == 4)
            cout << "Rajesh" << endl;
        else if (n / k == 0)
            cout << "Howard" << endl;
    }
    else {
        if (n / k == 0)
            cout << "Sheldon" << endl;
        else if (n / k == 1)
            cout << "Leonard" << endl;
        else if (n  / k == 2)
            cout << "Penny" << endl;
        else if (n  / k == 3)
            cout << "Rajesh" << endl;
        else if (n / k == 4)
            cout << "Howard" << endl;
    }
}