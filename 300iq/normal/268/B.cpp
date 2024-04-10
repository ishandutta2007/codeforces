#include <iostream>
#include<math.h>
using namespace std;

int main()
{
int n;
int a = 0;
cin>>n;
int f[n];
f[0]=n;
for(int i = 1; i<=n; i++){

f[i]= i * (n - i);

}
for(int i = 0; i<n; i++){
a+=f[i];
}
cout<<a;
}