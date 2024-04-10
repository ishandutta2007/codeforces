#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
 int n;
 cin >> n;
 n-=1;
 int p = 0;
 int secret = pow(2.0, p);
 while(5*secret<=n){
    n-=5*secret;
    p++;

    secret = pow(2.0, p);
 }
int numb = n/pow(2.0,p);
string guys[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
cout<<guys[numb];

}