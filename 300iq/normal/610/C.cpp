#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;


void builder (string s, int n){
    int m = s.length();
    if (m == n) cout << s << endl;
    else {
        string s1 = s, s2 = s;

        for (int i = 0; i < m; i++){
            if (s[i] == '+'){
                s1 += '+';
                s2 += '*';
            }

            else {
                s2 += '+';
                s1 += '*';
            }
        }

        builder(s1, n);
        builder(s2, n);


    }


}


int main(){

    int k; cin >> k;

    int n = 1;
    for (int i =  0; i < k; i++) n *= 2;


    string s = "+";
    builder(s, n);

    /*int c = n;



    for (int i = 0; i < n ; i++){

        for (int j = 0; j < n; ){

        if (i == n-1 && j == n-2) {
            cout << "*+";
            break;
        }

        for (int m = 0; m < c; m++){
                        cout << '+';
                        j++;
            }

            if (c != n){

            for (int m = 0; m < c; m++){
                        cout << '*';
                        j++;
                }
                }
            }


            if (c > 1) c /= 2;
        cout << endl;
    }

    */


    return 0;
}