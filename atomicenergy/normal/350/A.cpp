#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m,x;
    int min=1000;
    int maxi=0;
    cin >> n >> m;
    for(int a=0; a<n; a++){
        cin >> x;
        if(x>maxi)
            maxi=x;
        if(x<min)
            min=x;
    }
    int b=max(2*min,maxi);
    bool c=true;
    for(int a=0; a<m; a++){
        cin >> x;
        if(x<=b)
            c=false;
    }
    if(c==false)
        cout << -1;
    else
        cout << b;
}