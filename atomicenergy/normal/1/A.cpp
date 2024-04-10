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
    long long a,b,c,d,e;
    cin >> a >> b >> c;
    d=(b+c-1)/c;
    e=(a+c-1)/c;
    cout << d*e;
}