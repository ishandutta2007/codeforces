#include <cstdlib>
#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{

int n,t;

cin>>n>>t;

vector<char> a(n);

for(int i=0;i<n;i++)
cin>>a[i];

for(int i=0;i<t;i++)
{
        for(int j=0;j<n-1;j++)
        {
                if(a[j]=='B' && a[j+1]=='G')
                {
                             a[j]='G';
                             a[j+1]='B';
                             j++;
                }
        }
}
for(int i=0;i<n;i++)
cout<<a[i];
cout<<endl;
//system("pause");

return 0;
 
}