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
    int a[3][3];
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    cin>>a[i][j];
    for(int i=1;i<=100000;i++)
    if( (a[1][0]+a[1][2]+i) == (a[2][1]+a[0][1]+i) && (a[1][0]+a[1][2]+i) == (a[2][0]+a[0][2]+i))
    {
        int sum=a[1][0]+a[1][2]+i;
        int b=a[1][0]+a[1][2]+i;
        int n=-(a[1][0]-a[2][1]);
        double x=(a[1][0]+a[1][2]+i-n-i)/2;
        if(x-int(x)==0 && x+n+a[1][0]+a[2][0]==sum && x+n+a[0][1]+a[0][2]==sum && x+a[2][0]+a[2][1]==sum && x+a[0][2]+a[1][2]==sum)
        {
                       int sec=x+n;
                       a[0][0]=sec;
                       a[1][1]=i;
                       a[2][2]=x;
                       for(int i=0;i<3;i++)
                       {
                       for(int j=0;j<3;j++)
                       cout<<a[i][j]<<' ';
                       cout<<endl;
                       }
                       break;
        }
    }
    
    
    //system("pause");
    return EXIT_SUCCESS;
}