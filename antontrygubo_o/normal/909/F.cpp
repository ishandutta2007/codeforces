#include<iostream>
#include<algorithm>
#include<random>
#include<string>
using namespace std;

int max2(int n)
{
    int a = 1;
    while (n>1) {n=n/2; a*=2;}
    return a;
}

int main()
{
int n;
cin>>n;
int k =n;
if (n%2==1) cout<<"NO"<<endl;

else
    {
    cout<<"YES"<<endl;

    int a[n+1] = {0};


    while (n>2)
    {

        int k = 2*max2(n)-1;
        for (int i = n; i>=k-n; i--) {a[i]=k-i; }
        n = k-n-1;
    }
    if (n==2) {a[1] = 2; a[2]=1;}
    for (int i = 1; i<=k; i++) cout<<a[i]<<' ';
    cout<<endl;
    }


n = k;
int c = n;
if (max2(n)==n) {cout<<"NO"; return 0;}
if (n<=5) {cout<<"NO"; return 0;}
if (n==6) {cout<<"YES"<<endl<<5<<' '<<3<<' '<<2<<' '<<6<<' '<<1<<' '<<4; return 0;}
if (n==7) {cout<<"YES"<<endl<<5<<' '<<3<<' '<<2<<' '<<6<<' '<<7<<' '<<4<<' '<<1; return 0;}
int a[n+1] = {0};
for (int i = 0; i<=n; i++) a[i]=0;
a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 6; a[5]=7; a[6]=4; a[7]=1;
while (n>7)
{
    k = max2(n);
    for (int j = 0; j<=n-k; j++) a[k+j]=k+(j+1)%(n-k+1);
        n=k-1;
}
cout<<"YES"<<endl;
for (int i = 1; i<=c; i++) cout<<a[i]<<' ';

}