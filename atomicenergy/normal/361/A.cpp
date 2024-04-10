#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#define for(a,b) for(int a=0; a<b; a++)
using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    for(a,n){
        for(b,n){
            if(a==b)
                cout << k;
            else
                cout << "0";
            cout << " ";
        }
        cout << endl;
    }

}