#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

#define MAX 100
#define test(a) cout << "TEST " << a << endl;
#define go(a,b) for(int a=0; a<b; a++)
#define case(a) fout << "Case #"<< a << ": " <<
using namespace std;



int main()
{
    int a,b;
    string s;
    cin >> a >> b;
    cin >>s;
    if(2*b>a+1){
        go(c,a-b){
            cout << "RIGHT" << endl;
        }
        go(c,a-1){
            cout << "PRINT "<<s[a-1-c] << endl << "LEFT" << endl;
        }
        cout << "PRINT " << s[0];
    }
    else{
     go(c,b-1){
        cout << "LEFT" << endl;
     }
     go(c,a-1){
            cout <<"PRINT "<< s[c] << endl << "RIGHT" << endl;
        }
        cout << "PRINT " << s[a-1];
    }


}