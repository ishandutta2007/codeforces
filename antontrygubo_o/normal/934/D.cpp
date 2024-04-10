#include<bits/stdc++.h>
using namespace std;

int main()
{
long long p, k;
cin>>p>>k;
vector<int> coefs;
while (p!=0)
{
    int c = p%k;
    if (c<0) c+=k;
    coefs.push_back(c);
    p = -(p-c)/k;
}
cout<<coefs.size()<<endl;
for (int i = 0; i<coefs.size(); i++) cout<<coefs[i]<<' ';

}