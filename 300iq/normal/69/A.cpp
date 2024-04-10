#include <iostream>
long long x,y,z;
using namespace std;

int main()
{
x = 0;
y = 0;
z = 0;
long long n;
cin>>n;
for(long long  i = 0; i< n; i ++){
    long long bx,by,bz;
    cin>>bx>>by>>bz;
    x+=bx;
    y+=by;
    z+=bz;
}
if(x==0&y==0&&z==0){
    cout<<"YES";
}
else{
    cout<<"NO";
}


}