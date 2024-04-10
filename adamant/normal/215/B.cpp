#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    cout.setf(ios::fixed);
    cout.precision(7);
    
    int n;
    
    cin>>n;
    
    double*x=new double[n];
    
    for(int i=0;i<n;i++)
    {
            cin>>x[i];
    }
    
    int m;
    
    cin>>m;
    
    double*y=new double[m];
    
    for(int i=0;i<m;i++)
    {
            cin>>y[i];
    }
    
    int o;
    
    cin>>o;
    
    double*z=new double[o];
    
    for(int i=0;i<o;i++)
    {
            cin>>z[i];
    }
    
    double A,B;
    
    cin>>A>>B;
    
    double otn=A/B;
    
    double r1=*max_element(x,x+n);
    
    double P1=*max_element(y,y+m);
    
    double P2=*min_element(z,z+o);
    
    double P=P1/P2;
    
    cout<<sqrt(r1*r1/(otn/P+1))<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}