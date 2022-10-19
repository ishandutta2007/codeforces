#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;



int main(){
    int a,b,c;
    int total=0;
    cin >> a >> b >> c;
    int d;
    for(int e=0; e<a; e++){
    cin >> d;
    if(d==1){
        if(b>0)
            b--;
        else
            total++;
    }
    else{
        if(c>0)
            c--;
        else if(b>0)
            b--;
        else
            total++;
    }
    }
    cout << total;
}