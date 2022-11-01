#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int n,s;
int t=-1;
cin>>n>>s;
while(n--)
{
int x,y;
cin>>x>>y;
if(s*100>=x*100+y)
    t=max(t,(100-y)%100);
}
cout<<t;

}