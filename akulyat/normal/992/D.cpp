#include <bits/stdc++.h>

using namespace std;


const long long kk=1000;
const long long inf=kk*kk*kk*kk*kk*kk*8;



long long n,k,i,ans;
vector <long long> m,sum,b,bef,aft,rsum;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<n; i++)
  {long long a; cin>>a; m.push_back(a); }

sum.push_back(0);
for (auto i:m)
  sum.push_back(sum.back()+i);


long long ed=0;
long long j=0;
for (auto i:m)
  {
  if (i==1)
    ed++;
  else
    {
    bef.push_back(ed);
    ed=0;
    b.push_back(i);
    rsum.push_back(sum[j+1]);
    }
  j++;
  }

long long l=b.size();
for (i=1; i<l; i++)
  aft.push_back(bef[i]);
aft.push_back(ed);


long long ans=0;
if (k==1)
  ans+=n;
for (i=0; i<l; i++)
  {
  long long v=b[i];
  long long last=i;
  long long p=1;
  if (k==1)
    {
    last++;
    p=v;
    }
  long long before=bef[i];
  long long summa=rsum[i]-v;
  while (last<l&&p<inf/b[last])
    {
    p*=b[last];
    long long a1=before;
    long long b1=aft[last];
    long long s=rsum[last]-summa;
    if (p%k==0)
      {
      long long raz=p/k-s;
      if (raz>=0/*&&raz<=(a1+b1)*/)
        {
        long long add=raz+1;
        add=min(add, a1+1);
        add=min(add, b1+1);
        add=min(add, -raz+a1+b1+1);
//        cout<<i<<' '<<last<<' '<<add<<endl;
//        cout<<p<<' '<<s<<' '<<raz<<endl<<endl;
        if (raz<=(a1+b1))
          ans+=add;
        }
      }
    last++;
    }
  }

cout<<ans;




    return 0;
}