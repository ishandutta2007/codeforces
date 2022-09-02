#include <bits/stdc++.h>
using namespace std;

//0 - vratar;
//1-zaasch
//2 - nap

vector<int> vr;
vector<int> za;
vector<int> nap;

vector<int> countv;
vector<int> countz;
vector<int> countn;

long long s2(long long n)
{
    return n*(n-1)/2;
}

long long s3(long long n)
{
    return n*(n-1)*(n-2)/6;
}

int main()
{

int v, z, n;
cin>>v>>z>>n;
int temp;
for (int i = 0; i<v; i++) {cin>>temp; vr.push_back(temp);}
for (int i = 0; i<z; i++) {cin>>temp; za.push_back(temp);}
for (int i = 0; i<n; i++) {cin>>temp; nap.push_back(temp);}
sort(vr.begin(), vr.end());
sort(za.begin(), za.end());
sort(nap.begin(), nap.end());

int idx = 0;
for (int i = 0; i<=100000; i++) countv.push_back(0);
for (int i = 0; i<=100000; i++) countz.push_back(0);
for (int i = 0; i<=100000; i++) countn.push_back(0);

for (int i = 0; i<vr.size(); i++) countv[vr[i]]=1;
for (int i = 1; i<=100000; i++)
{
    if (countv[i]==1) countv[i]=countv[i-1]+1;
    else countv[i] = countv[i-1];
}
for (int i = 0; i<za.size(); i++) countz[za[i]]=1;
for (int i = 1; i<=100000; i++)
{
    if (countz[i]==1) countz[i]=countz[i-1]+1;
    else countz[i] = countz[i-1];
}

for (int i = 0; i<nap.size(); i++) countn[nap[i]]=1;

for (int i = 1; i<=100000; i++)
{
    if (countn[i]==1) countn[i]=countn[i-1]+1;
    else countn[i] = countn[i-1];
}

for (int i = 0; i<=40; i++)
{
   // cout<<i<<' '<<countv[i]<<' '<<countz[i]<<' '<<countn[i]<<endl;
}

//for (int i = 0; i<=20; i++) cout<<countn[i]<<' ';

long long total = 0;
long long sposob = 1;
for (int i = 0; i<vr.size(); i++)
{
    sposob = 1;
    sposob*=s2(countz[min(2*vr[i], 100000)]-countz[vr[i]]);
    sposob*=s3(countn[min(2*vr[i], 100000)]-countn[vr[i]]);
    total+=sposob;
    //cout<<"sposob"<<' '<<sposob<<endl;
}

//cout<<endl;
for (int i = 0; i<za.size(); i++)
{
    sposob = 1;
    sposob*=(countv[min(2*za[i], 100000)]-countv[za[i]]);
    //cout<<"sposob"<<' '<<sposob<<endl;
    sposob*=(countz[min(2*za[i], 100000)]-countz[za[i]]);
    //cout<<"sposob"<<' '<<sposob<<endl;
    sposob*=s3(countn[min(2*za[i], 100000)]-countn[za[i]]);
    total+=sposob;
    //cout<<za[i]<<' '<<"sposobza"<<' '<<sposob<<endl;
}
//cout<<endl;
//cout<<endl;

for (int i = 0; i<nap.size(); i++)
{
    sposob = 1;
    sposob*=(countv[min(2*nap[i], 100000)]-countv[nap[i]]);
    //cout<<"sposob"<<' '<<sposob<<endl;
    sposob*=s2(countz[min(2*nap[i], 100000)]-countz[nap[i]]);
    //cout<<"sposob"<<' '<<sposob<<endl;
    sposob*=s2(countn[min(2*nap[i], 100000)]-countn[nap[i]]);
    total+=sposob;
    //cout<<nap[i]<<' '<<"sposobnap"<<' '<<sposob<<endl;
}
cout<<total;
}