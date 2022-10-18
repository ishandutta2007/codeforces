#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

struct troll
{
  int t;
  double t_a;
  double ans;
  int v_max;
  double v;
  int u;     
};

int main(int argc, char *argv[])
{
    cout.setf(ios::fixed);
    cout.precision(10);
    
    double n,a,d;
    
    cin>>n>>a>>d;
    
    troll*all=new troll[int(n)];
    
    for(int i=0;i<n;i++)
    {
            all[i].u=a;
            all[i].v=0;
     cin>>all[i].t>>all[i].v_max;       
    }
    
    double t_1=double(all[0].v_max)/a;
    double t_2;
    if( a*t_1*t_1/2 > d )
    {
        t_2=0;
        t_1=sqrt(2*d/a);
    }
    else
    t_2=double(d-a*t_1*t_1/2)/double(all[0].v_max);
    
    //cout<<t_1<<' '<<t_2<<endl;
    
    //cout<<3.123456789<<endl;
    
    all[0].t_a=t_1+t_2;
    
    all[0].ans=all[0].t_a+all[0].t;
    
    cout<<all[0].ans<<endl;
    
    for(int i=1;i<n;i++)
    {
            
    t_1=double(all[i].v_max)/a;
    if( a*t_1*t_1/2 > d )
    {
        t_2=0;
        t_1=sqrt(2*d/a);
    }
    else
    t_2=double(d-a*t_1*t_1/2)/double(all[i].v_max);
    
    all[i].t_a=t_1+t_2;
    
    all[i].ans=all[i].t_a+all[i].t;
    
    if(all[i].ans < all[i-1].ans)
    all[i].ans=all[i-1].ans;
    cout<<all[i].ans<<endl;
            
    }
    
    
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}