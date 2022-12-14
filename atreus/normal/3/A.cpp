#include <iostream>
#include <string>

using namespace std;

int main (){
    string s, t;
    cin >> s >> t;
    int T = t[0] - '0';
    int S = s[0] - '0';
    int L = T - S;
    int D = (t[1] - '0') - (s[1] - '0');
    int l = L;
    int d = D;
    if (l < 0)
        l = -l;
    if (d < 0)
        d = -d;
    int DL;
    int mod;
    if (l > d){
        DL = d;
        cout << l << endl;
        mod = l - d;
    }
    else{
        DL = l;
        cout << d << endl;
        mod = d - l;
    }
    if (D > 0 && L > 0){
        for (int i = 1; i <= DL; i++){
            cout << "RU" << endl;
            D -= 1;
            L -= 1;
        }
    }
    else if (D < 0 && L > 0){
        for (int i = 1; i <= DL; i++){
            cout << "RD" << endl;
            L -= 1;
            D += 1;
        }
    }
    else if (D > 0 && L < 0){
        for (int i = 1; i <= DL; i++){
            cout << "LU" << endl;
            D -= 1;
            L += 1;
        }
    }
    else if (D < 0 && L < 0){
        for (int i = 1; i <= DL; i++){
            cout << "LD" << endl;
            D += 1;
            L += 1;
        }
    }
    if (L > 0 && D == 0)
        for (int i = 1; i <= L; i++)
            cout << "R" << endl;
    else if (L < 0 && D == 0)
        for (int i = -1; i >= L; i--)
            cout << "L" << endl;
    else if (D > 0 && L == 0)
        for (int i = 1; i <= D; i++)
            cout << "U" << endl;
    else if (D < 0 && L == 0)
        for (int i = -1; i >= D; i--)
            cout << "D" << endl;
}