#include <iostream>

using namespace std;

int main () {
    int m = 0;
    int a[4];
    for (int i = 0; i < 4; i++){
        cin >> a[i];
    }
    for (int i = 0; i < 4; i++){
        for (int j = i + 1; j < 4; j++){
        if (i != j){
            if (a[i] == a[j])
                m++;
        }
        else
            break;
        }
    }
    if (m == 6)
        cout << "3" << endl;
    else if (m == 3)
        cout << "2" << endl;
    else
        cout << m;

}