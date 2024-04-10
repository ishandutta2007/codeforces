#include<bits/stdc++.h>
using namespace std;

int a[1000001] = {0};


int f(int n)
{
    int res = 1;
    while (n>0) 
    {
        if (n%10!=0) res*=(n%10);
        n/=10;
    }
return res;
}

int b[1000001][10] = {0};

int main()
{
for (int i = 1; i<=9; i++) a[i] = i;
for (int i = 10; i<1000001; i++) a[i] = a[f(i)];
for (int i = 1; i<=1000000; i++)
{
    for (int j = 1; j<=9; j++) b[i][j] = b[i-1][j];
    b[i][a[i]]++;
}

int q;
int l, r, k;
cin>>q;
for (int i = 0; i<q; i++)
{
    cin>>l>>r>>k;
    cout<<b[r][k]-b[l-1][k]<<endl;
}

}