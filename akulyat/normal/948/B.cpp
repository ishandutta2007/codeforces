#include <bits/stdc++.h>

using namespace std;
const long op=100;
long k;
long mini;
vector <long> p;
void zap(long k, short por)
{
mini=min(mini, k);
p.push_back(k);
//       cout<<"path is ";
//       for (long i=0; i<p.size(); i++)
//         cout<<p[i]<<' ';
//       cout<<endl;
if (por<2)
{
long k1=k;
vector <long> del;
for (long long i=2; i<long(sqrt(k1))+1; i++)
  if (k1%i==0)
    {
    del.push_back(i);
    while (k1%i==0)
      k1/=i;
    }
if (k1!=1)
  del.push_back(k1);
              //cout<<k<<endl;
              //for (long i=0; i<del.size(); i++)
              //  cout<<del[i]<<' ';
              //cout<<endl;
for (long i=0; i<del.size(); i++)
  {
  for (long j=0; j<op; j++)
    if ((del[i]<k-del[i]+1+j)&&(j<del[i]-1)&&(k-del[i]+1+j<=k))
      zap(k-del[i]+1+j, por+1);
  }
}
p.pop_back();
}

int main()
{
cin>>k;
mini=k;
zap(k, 0);
cout<<mini;

    return 0;
}