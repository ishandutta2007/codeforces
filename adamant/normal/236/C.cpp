#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

#define u64 long long

using namespace std;
vector<int> prost;

void wr()
{
     
}

int func(int n)
{
    for(int i=prost.size()-1;i>=0;i--)
    {
            if(prost[i]<=n)
            return i;
    }
}


int main(int argc, char *argv[])
{
/*    int size = 100;
    cin>>size;
int array[size];
 
for(int k = 0; k < size; k++)
array[k] = k;
 
array[1] = 0;
 

for(int i = 2; i < sqrt(size); i++)
{
if(array[i] != 0)
{
for(int j = i * 2; j < size; j += i)
{
array[j] = 0;
}
}
}
vector<int> prost;
    for(int i = 0; i < size; i++)
if(array[i] != 0)
prost.push_back(array[i]);
*/
long long n;
    cin>>n;
    if(n==2 || n==1)
    cout<<n<<endl;
    else
    {
        if(n%2)
    cout<<n*(n-1)*(n-2)<<endl;
    else
    {
        long long ans;
    if(!(n%3))
    ans=max(n*(n-1)*(n-3)/3,max(n*(n-1)*(n-2)/2,(n-1)*(n-2)*(n-3)));
    else
    ans=max(n*(n-1)*(n-3),max(n*(n-1)*(n-2)/2,(n-1)*(n-2)*(n-3)));
    cout<<ans<<endl;
}
    }

    //system("PAUSE");
    return EXIT_SUCCESS;
}