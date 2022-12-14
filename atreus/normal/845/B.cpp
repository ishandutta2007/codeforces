#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string s, a, b;
    cin >> s;
    int cnt = 0, cont = 0;
    for (int i = 0; i < 3; i++){
        cnt += s[i] - '0';
        a += s[i];
    }
    for (int i = 3; i < 6; i++){
        cont += s[i] - '0';
        b += s[i];
    }
    if (cnt < cont){
        swap (cnt, cont);
        swap (a, b);
    }
    int k = cnt - cont;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (a[j] < a[j + 1])
                swap (a[j], a[j + 1]);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (b[j] > b[j + 1])
                swap (b[j], b[j + 1]);
    int inc1 = 0, inc2 = 0, ans = 0;
//    cout << a << " " << b << endl;
    while (k > 0){
        if (a[inc1] - '0' > 9 - (b[inc2] - '0')){
            k -= a[inc1] - '0';
            inc1 ++;
            ans ++;
        }
        else {
            k -= 9 - (b[inc2] - '0');
            inc2 ++;
            ans ++;
        }
    }
    cout << ans << endl;
}