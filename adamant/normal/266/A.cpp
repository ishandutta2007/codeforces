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

int n;

cin>>n;

vector<char> a(n);

for(int i=0;i<n;i++)
cin>>a[i];
int ans=0;
for(int i=0;i<n-1;i++)
if(a[i]==a[i+1])
ans++;
cout<<ans<<endl;
//system("pause");

return 0;
 
}