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
    ofstream out("output.txt");
    ifstream in("input.txt");
    int n;
    in>>n;
    double*a=new double[n];
    for(int i=0;i<n;i++)
    in>>a[i];
    if(n==2)
    {
            if(a[0]*2>=a[1])
            out<<0<<endl;
            else
            out<<1<<endl;
            return 0;
    }
    sort(a,a+n);

    int min=n+1;
    int prj=n-2;
    for(int i=0;i<n-1;i++)
    if(a[i]*2>=a[n-1])
    {
                      prj=i;
                      min=prj;
                      break;
    }
    for(int i=n-2;i>0;i--)
    {
            int c=n-i-1;
            if(c>=min)
            goto end;
            for(int j=prj-1;j>=0;j--)
            {
                    if(j==0)
                    {
                    min=j+c;
                    goto end;
                    }
                    if(a[j-1]*2<a[i])
                    {
                    prj=j;
                    min=j+c;
                    break;
                    }
            }
    }
    end:
        
    out<<min<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}