#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>

#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m,n,d;
    cin >> m;
    n=0;
    while (m>=0){
        n++;
        d=n*(n+1);
        d/=2;
        m-=d;

        //cout << n << " " << m << " " << d << endl;
    }
    cout << n-1 << endl;


}