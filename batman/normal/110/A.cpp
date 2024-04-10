#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int p;
string s;
int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]=='4' || s[i]=='7')
            p++; 
     if(p==0)
     {
     cout<<"NO"; 
     return 0;
     }
                
     while(p)
     {
         if(p%10!=4 && p%10!=7)
         {
             cout<<"NO";
             return 0;
         }
         p/=10;
     }    
     cout<<"YES";
    return 0;
}