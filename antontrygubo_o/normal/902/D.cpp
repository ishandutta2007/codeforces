#include<iostream>

using namespace std;

int main()
{
int a[200] = {0};
int b[200] = {0};
int c[200] = {0};
a[0] = 1;
b[1] = 1;
int n;
cin>>n;
for (int i = 2; i<=n; i++)
{
    for (int j = 1; j<=i; j++) c[j] = (b[j-1]+a[j])%2;
    c[0] = a[0];
    for (int j = 0; j<=i; j++) a[j] = b[j];
    for (int j = 0; j<=i; j++) b[j] = c[j];
}
cout<<n<<endl;
for (int i = 0; i<=n; i++) cout<<b[i]<<' ';
cout<<endl;
cout<<n-1<<endl;
for (int i = 0; i<=n-1; i++) cout<<a[i]<<' ';
cout<<endl;

}