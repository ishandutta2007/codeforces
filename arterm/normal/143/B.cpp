#include <cstdlib>
#include <iostream>

using namespace std;



int main()
{
    long a[200],b[200],l=0,d=0,i,r,j;
    bool sign=1;
    char ch;
    cin>>ch;
    if (ch=='-')
    sign=0;
    else
    a[l++]=ch-'0';
    while (cin>>ch){
          if (ch=='.')
          break;
          a[l++]=ch-'0';
          }
    if (ch=='.')
    while (cin>>ch && d<2)
    b[d++]=ch-'0';
    if (!sign)
    cout<<"(";
    cout<<"$";
    r=l%3;
    for (i=0; i<r; ++i)
    cout<<a[i];
    if (i!=l && r>0)
    cout<<",";
    for (;i<l; i+=3){
        for (j=0; j<3; ++j)
        cout<<a[i+j];
        if (i+3!=l)
        cout<<",";
        }
    cout<<".";
    switch (d){
           case 0: cout<<"00"; break;
           case 1: cout<<b[0]<<0; break;
           case 2: cout<<b[0]<<b[1]; break;
           }
    if (!sign)
    cout<<")";
    return 0;
}