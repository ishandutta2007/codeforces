#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdlib.h>
using namespace std;

string s;
int x,y,k;
int main()
{
    cin>>s;
    if(s.size()>1)
        x=s[s.size()-2]-0;
    y=s[s.size()-1]-0;
    k=x*10+y;
    if(k%4==0)
        cout<<4;      
    else
        cout<<0;
                      
    
    return 0;
}