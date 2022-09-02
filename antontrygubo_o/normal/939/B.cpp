#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main() 
{
long long n, k;
cin>>n>>k;
long long a[k];
for (long long  i = 0; i<k; i++) cin>>a[i];
int which = -1;
long long number = -1;
for (int i = 0; i<k; i++)
{
    if (n-(n%a[i])>number) {which = i; number = n-(n%a[i]);}
}
cout<<which+1<<' '<<(n-(n%a[which]))/a[which];
}