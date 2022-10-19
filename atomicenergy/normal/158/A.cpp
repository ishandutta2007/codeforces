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
    int n, k, b;
    int array[50];
    cin >> n >> k;
    for(a, n){
        cin >> array[a];
    }
    int total=k-1;
    if(array[k-1]==0){
        while (array[total]==0){
            total--;
        }
        total++;
    }
    else{
        while (array[total]==array[k-1]){
            total++;
        }

    }
    cout << total;
}