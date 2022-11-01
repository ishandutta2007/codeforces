#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


long long n,a,b,p;
int main()
{
    
    cin>>n;
    for(a=0;a<=(1000*300);a++)
    {
        int q=(n-(a*4));
        if(q<0)
            break;
        if(q%7==0)
        {
            p++;
            b=q/7;
            break;
        }
    }
    if(p==0)
        cout<<-1;
    else
    {
        for(int i=0;i<a;i++)
            cout<<4;
        for(int i=0;i<b;i++)
            cout<<7;    
    }   
    return 0;
}