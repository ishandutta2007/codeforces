#include <iostream>

using namespace std;

int main (){
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    int dt;
    if (d2 > d1){
        dt = d1;
        if (d1 + d2 > d3)
            dt += d3;
        else
            dt += (d1 + d2);
        if (d2 > d3 + d1)
            dt += d3 + d1;
        else
            dt += d2;
    }
    else{
        dt = d2;
        if (d1 + d2 > d3)
            dt += d3;
        else
            dt += (d1 + d2);
        if (d1 > d3 + d2)
            dt += d3 + d2;
        else
            dt += d1;
    }
    cout << dt << endl;
}