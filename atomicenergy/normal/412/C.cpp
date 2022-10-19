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
    string d;
    cin >> a;
    vector<string> v;
    go(c,a){
        cin >> d;
        v.push_back(d);
    }
    char f;

    go(c,v[0].length()){
        f='.';
        go(e,v.size()){
            if((v[e][c]!='?')&&(f!=v[e][c])&&(f!='.'))
                f='?';
            if((v[e][c]!='?')&&(f=='.')&&(f!='?'))
                f=v[e][c];
        }
        if(f=='.')
            cout << "a";
        else
            cout << f;

    }


}