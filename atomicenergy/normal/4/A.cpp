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
    int a;
    cin >> a;
    if(a%2==0&&a!=2)
        cout << "YES";
    else
        cout << "NO";
}