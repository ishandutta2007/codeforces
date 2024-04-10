#include<iostream>

using namespace std;


int main()
{
int a;
int b;
int c;
cin>>a>>b>>c;
a = a%b;
int current = 10*a/b;
int idx = 1;
while ((current!=c)&&(idx<=b))
{
   a = (10*a)%b;
   idx++;
   current = 10*a/b;
}
if (idx>b) cout<<-1;
else cout<<idx;
}