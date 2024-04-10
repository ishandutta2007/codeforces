#include <iostream>

using namespace std;
/*
string make_lower_case(string c) {
    for (int i = 0; i < 100; i++)
        if (c[i] >= 'A' && c[i] <= 'Z')
            c[i] = c[i] - 'A' + 'a';
    return c;
}

string make_upper_case(string d) {
    for (int i = 0; i < 100; i++)
        if (d[i] >= 'a' && d[i] <= 'z')
            d[i] = d[i] - 'a' + 'A';
    return d;
}
*/
int main () {
    string c;
    cin >> c;
    int uc = 0, lc = 0;
    int n = c.length();
    if (n >= 1 && n <= 100){
        for (int i = 0; i < n; i++){
            if (c[i] >= 'A' && c[i] <= 'Z')
                uc ++;
            else if (c[i] >= 'a' && c[i] <= 'z')
                lc ++;
        }
        if (lc >= uc){
            //cout << make_lower_case(c) << endl;
            for (int i = 0; i < 100; i++)
                if (c[i] >= 'A' && c[i] <= 'Z')
                    c[i] = c[i] - 'A' + 'a';
            cout << c;
        }
        else{
            //cout << make_upper_case(c) << endl;
        for (int i = 0; i < 100; i++)
            if (c[i] >= 'a' && c[i] <= 'z')
                c[i] = c[i] - 'a' + 'A';
        cout << c;
        }
    }
}