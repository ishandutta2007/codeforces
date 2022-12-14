#include <iostream>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    if (n >= 3){
        if (n % 2 == 0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else
        cout << "No" << endl;
}