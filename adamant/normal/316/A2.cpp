#include <iostream>
#include <algorithm>

using namespace std;

main()
{
string a;
cin>>a;
int b[10]={0};
int w=0;
for(int i=0;i<a.size();i++)
if(a[i]=='?')
w++;
else if(a[i]>='A' && a[i]<='J')
b[a[i]-'A']++;

sort(b,b+10);
int x=0;
for(int i=0;i<10;i++)
if(b[i])
x++;

if(x==0 && w==0)
cout<<1<<endl;
else
{
int numx=1;
for(int i=0;i<x;i++)
numx*=10-i;
if(a[0]<'1' || a[0]>'9')
{
if(x==0)
numx*=10,w--;
numx/=10;
numx*=9;
}
cout<<numx;
for(int i=0;i<w;i++)
cout<<'0';

}
}