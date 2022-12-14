#include <iostream>

using namespace std;

int main (){
    int n, Mishka = 0, Chris = 0;
    cin >> n;
    int a[n + 10], b[n + 10];
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        if (a[i] > b[i])
            Mishka++;
        else if (a[i] < b[i])
            Chris++;
    }
    if (Mishka > Chris)
        cout << "Mishka" << endl;
    else if(Mishka == Chris)
        cout << "Friendship is magic!^^" << endl;
    else
        cout << "Chris" << endl;
}