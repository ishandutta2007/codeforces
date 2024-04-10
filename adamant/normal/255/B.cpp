#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string a;
    cin>>a;
    
    int x=0,y=0;
    for(int i=0;i<a.size();i++)
    if(a[i]=='x')
    x++;
    else
    y++;
    
    if(x>y)
    for(int i=0;i<x-y;i++)
    cout<<'x';
    else
    for(int i=0;i<y-x;i++)
    cout<<'y';
    
    return EXIT_SUCCESS;
}