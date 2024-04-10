#include <bits/stdc++.h>

using namespace std;
int main() 
{
long long n;
cin>>n;
long long k1, k2;
cin>>k1>>k2;
int a[n];
int b[n];
for (int i = 0; i<n; i++) cin>>a[i];
for (int i = 0; i<n; i++) cin>>b[i];
long long c[n];
for (int i = 0; i<n; i++) c[i] = fabs(a[i]-b[i]);
multiset<long long> My;
for (int i = 0; i<n; i++) My.insert(-c[i]);

multiset<long long>::iterator here;


for (int i = 0; i<k1+k2; i++)
{

    long long kek = *My.begin();
    auto itr = My.find(kek);
    if(itr!=My.end()){
    My.erase(itr);
    }
    if (kek<0) kek++;
    else kek--;
    My.insert(kek);

}

long long diff = 0;

for (here = My.begin(); here!=My.end(); here++) diff+=(*here)*(*here);
cout<<diff;

}