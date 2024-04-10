#include <iostream>

using namespace std;

int main (){
    int s, t = 0, n2 = 0, n3 = 0;
    cin >> s;
    int a[s];
    for (int i = 0; i < s; i++){
        cin >> a[i];
        if (a[i] == 4)
            t++;
    }
    for (int i = 0; i < s; i++)
        if (a[i] == 3)
            n3++;
    t += n3;
    if (n3 > 0){
        for (int i = 0; i < s; i++){
            if (a[i] == 1){
                a[i] = 4;
                    n3--;
                if (n3 == 0)
                    break;
            }
        }
    }
    for (int i = 0; i < s; i++)
        if (a[i] == 2)
            n2++;
    int nm2 = n2 % 2;
    if (nm2 == 0){
        t += n2 / 2;
    }
    else {
        t += n2 / 2;
        t ++;
        int m = 2;
        for (int i = 0; i < s; i++){
            if (a[i] == 1){
                m++;
                a[i] = 4;
                if (m == 4)
                    break;
            }
        }
    }
    for (int i = 0; i < s; i++)
        if (a[i] == 1){
            t++;
            for (int j = 0; j < s; j++)
                if (a[j] == 1 && j != i){
                    a[i] += 1;
                    a[j] = 4;
                    if (a[i] == 4)
                        break;
                }
        }

    cout << t << endl;
}