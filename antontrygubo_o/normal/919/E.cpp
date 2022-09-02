#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, p, x;
    cin>>a>>b>>p>>x;
    vector<int> residues;
    long long c = 1;
    residues.push_back(1);
    while ((c*a)%p!=1) 
    {
        c = (c*a)%p;
        residues.push_back(c);
    }
int pokazatel = residues.size();
vector<int> r;
r.push_back(0);
r.push_back(1);
for (int i = 2; i<p; i++) r.push_back((p - (p/i)*r[p%i]%p)%p);

//for (int i = 0; i<r.size(); i++) cout<<r[i]<<' ';
//cout<<endl;
//cout<<pokazatel<<endl;

long long summ = 0;
for (int i = 0; i<pokazatel; i++)
{
    long long remaind = residues[i];
    long long n1 = (b*r[remaind])%p;
    summ+=(x/(pokazatel*p));
    long long x1 = x%(pokazatel*p);
    long long k = (i-n1)%pokazatel;
    if (k<0) k+= pokazatel;
    if (k*p+n1<=x1) summ++;
    //cout<<i<<' '<<' '<<remaind<<' '<<n1<<' '<<k<<' '<<' '<<summ<<endl;
    
}
cout<<summ;

    
}