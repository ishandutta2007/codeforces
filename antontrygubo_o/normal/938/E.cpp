#include<bits/stdc++.h>
using namespace std;

long long a[1000000];
const long long N= 1000000007;

int main()
{
int n;
cin>>n;
if (n==1) {cout<<0; return 0;}
for (int i = 0; i<n; i++) cin>>a[i];
sort(a, a+n);
int idx = n-2;
long long res = 0;
long long  currentpow = 1;
while ((idx>=0)&&(a[idx]==a[idx+1])) idx--;
if (idx<0) {cout<<0; return 0;}

for (long long g = 1; g<=n-1-idx; g++) currentpow = (currentpow*g)%N;

//cout<<idx<<' '<<currentpow<<endl;

while (idx>=0)
{
    int count = 1;
    while ((idx>=1)&&(a[idx]==a[idx-1])) {count++; idx--; currentpow = (currentpow*(n-1-idx))%N; res = (res*(n-1-idx))%N;}
    res = (res*(n-idx))%N;
    long long resplus = (a[idx]*count)%N;
    resplus = (resplus*currentpow)%N;
    res = (res+resplus)%N;
    currentpow = (currentpow*(n-idx))%N;
    idx--;
}
cout<<res;


}