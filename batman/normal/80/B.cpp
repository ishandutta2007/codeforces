#include <iostream>
using namespace std;
double h2=0.0;
int h,m,a,b;
char s[5];
int main()
{
    
    cin>>s;
    a=s[0]-'0';
    b=s[1]-'0';
    h=a*10+b;
    if(h>11)
        h-=12;
    a=s[3]-'0';
    b=s[4]-'0';
    m=a*10+b;
    h2=((double)m/2)+h*30;
    m*=6;
    cout<<h2<<" "<<m<<endl;

    return 0;
}