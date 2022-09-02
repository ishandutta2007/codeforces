#include<bits/stdc++.h>
using namespace std;
//A[k+1][k+1]; (o n  n-k)
long long A[5001][5001] = {0};

const long long N = 1000000007;

long long deg2(int i)
{
    if (i==0) return 1;
    if (i%2==0) return ((deg2(i/2))*(deg2(i/2)))%N;
    return 2*(((deg2(i/2))*(deg2(i/2)))%N)%N;
}


int main()
{
long long n, k;
cin>>n>>k;
long long S = 1;
for (int i = n; i>=max(n-k, S); i--)
{
    A[n-i][0] = deg2(i)-1;
}

for (int i = 1; i<=k; i++)
{
    for (int j = n; j>=max(n-k+i, S); j--)
    {A[n-j][i] = ((A[n-j][i-1]-A[n-j+1][i-1])*j)%N;
    if (A[n-j][i]<0) A[n-j][i]+=N;}
}

cout<<A[0][k];

}