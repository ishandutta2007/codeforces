#include <cstdlib>
#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <fstream>

using namespace std;


int main()
{
string s;
cin>>s;
int n=s.size();
int*l=new int[1000010];
int*r=new int[1000010];
for(int i=0;i<n;i++)
{
        if(s[i]=='l')l[++l[0]]=i+1;
        else if(s[i]=='r')r[++r[0]]=i+1;
}
for(int i=1;i<=r[0];i++) cout<<r[i]<<endl;
for(int i=l[0];i>0;i--)cout<<l[i]<<endl;
//system("pause");

return 0;
 
}