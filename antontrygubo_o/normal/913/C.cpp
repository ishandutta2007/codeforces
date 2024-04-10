#include <bits/stdc++.h>

using namespace std;

long long mintake(int L, long long a[], bool take[], int n)
{
    if (!take[n-1]) return mintake(L, a, take, n-1);
    long long L1 = L;
    long long c = 1<<(n-1);
    long long sum = 0;
    sum=(L1/c)*a[n-1]; L1 = L1%c;
    if (L1==0) return sum;
    else return sum + min (a[n-1], mintake(L1, a, take, n-1));
}

int main()
{
 
int n, L;
cin>>n>>L;
long long a[n];
long long b[n];
bool take[n];
for (int i = 0; i<n; i++) {cin>>a[i]; take[i] = true;}
for (int i = 0; i<n; i++) {b[i] = a[i]; b[i] = b[i]<<30-i;}
for (int i = 0; i<n; i++)
    {for (int j = i+1; j<n; j++)
    {if (b[i]<b[j]) take[j]=false;}}
cout<<mintake(L, a, take, n);

}