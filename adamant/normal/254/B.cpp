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
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int n;
    
    in>>n;
    int days[465];
    for(int i=0;i<465;i++)
    days[i]=0;
    int*m=new int[n];
    int*d=new int[n];
    int*p=new int[n];
    int*t=new int[n];
    int maxt=0;
    for(int i=0;i<n;i++)
    {
    in>>m[i]>>d[i]>>p[i]>>t[i];
    for(int j=1;j<=t[i];j++)
    {
            int c=100+d[i];
            if(m[i]==2)
                    c+=31;
            else if(m[i]==3)
                 c+=31+28;
            else if(m[i]==4)
                 c+=31+28+31;
            else if(m[i]==5)
                 c+=31+28+31+30;
            else if(m[i]==6)
                 c+=31+28+31+30+31;
            else if(m[i]==7)
                 c+=31+28+31+30+31+30;
            else if(m[i]==8)
                 c+=31+28+31+30+31+30+31;
            else if(m[i]==9)
                 c+=31+28+31+30+31+30+31+31;
            else if(m[i]==10)
                 c+=31+28+31+30+31+30+31+31+30;
            else if(m[i]==11)
                 c+=31+28+31+30+31+30+31+31+30+31;
            else if(m[i]==12)
                 c+=31+28+31+30+31+30+31+31+30+31+30;
            days[c-j]+=p[i];
            if(days[c-j]>maxt)
            maxt=days[c-j];
    }
    }
    
    out<<maxt<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}