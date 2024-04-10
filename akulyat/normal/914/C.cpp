#include <bits/stdc++.h>

using namespace std;

const long long pc=1000000007, sto=pc-2;
string s;
long long i,j,n,k,pa[2000];
long long ans=0,fac[2000],obr[2000];
long long mam[2000],st[2000];

long long obra(long long j)
{
long long z;
st[1]=j;
  for (int i=2; i<=40; i++)
    {
    st[i]=(st[i-1]*st[i-1])%pc;
    }
  z=1;
  for (int i=1; i<=40; i++)
    if (mam[i]==1)
      z=(z*st[i])%pc;
return z;
}
void pole()
{
fac[0]=1;
for (int i=1; i<1001; i++)
  fac[i]=(fac[i-1]*i)%pc;

long long vr=sto;
long u=1;
while (vr>0)
  {
  mam[u]=vr%2;
  vr=vr/2;
  u++;
  }
for (int j=u; j<40; j++)
  mam[j]=0;
/*for (int j=1; j<1001; j++)
  {
  st[0]=1;
  for (int i=1; i<=40; i++)
    {
    st[i]=(st[i-1]*j)%pc;
    }
  obr[j]=1;
  for (int i=1; i<=40; i++)
    if (mam[i]==1)
      obr[j]=(obr[j]*st[i])%pc;
  }
*/
}

void zap(long i)
{
long i1=i, k=0;
while (i1>0)
  {
  if (i1%2==1)
    k++;
  i1=i1/2;
  }
//pa[i]=k;
pa[i]=pa[k]+1;
}

/*(void addcf(long n, long k, short t)
{
if ((n>=k)&&(n>0)&&(k>0))
{
cout<<"c iz n po k vichet "<<n<<' '<<k<<' ';

ans+=((((fac[n]/fac[k])/fac[n-k])%pc)*t);
if (n>k)
  ans-=((((fac[n-1]/fac[k])/fac[n-1-k])%pc)*t);
if (ans>0)
  ans%=pc;
cout<<"I add "<<(((fac[n]/fac[k])/fac[n-k])%pc)*t-((((fac[n-1]/fac[k])/fac[n-1-k])%pc)*t)<<endl;
} else
  if (k==0)
  {
  ans+=t;
  cout<<"c iz n po k "<<n<<' '<<k<<' ';
  cout<<"I add   "<<t<<endl;
  }
}*/

void addc(long n, long k, short t)
{
if ((n>=k)&&(n>0)&&(k>0))
{
//cout<<"c iz n po k "<<n<<' '<<k<<' ';

ans+=((((fac[n]*obra(fac[k])%pc)*obra(fac[n-k]))%pc)*t);
  ans%=pc;
//cout<<"I add "<<(((fac[n]*obra(fac[k])%pc)*obra(fac[n-k]))%pc)*t<<' '<<obra(fac[k])<<' '<<obra(fac[n-k])<<endl;
} else
  if ((k==0)&&(n>=0))
  {
  ans+=t;
  //cout<<"c iz n po k "<<n<<' '<<k<<' ';
  //cout<<"I add   "<<t<<endl;
  }
if (ans<0)
  ans+=pc;
}

int main()
{
//cout<<"first"<<endl;
pole();
//cout<<obra(1)<<endl;
//cout<<obra(2)<<endl;
//cout<<obra(3)<<endl;
//cout<<(obra(4))<<endl;
//cout<<obra(pc-1)<<endl;
//cout<<obra(pc)<<endl;
  // cout << "Hello world!" << endl;
ans=0;
cin>>s;
n=s.size();
cin>>k;

if (k==0)
  {
  cout<<1<<endl;
  return 0;
  }
pa[1]=0;
for (i=2; i<=1000; i++)
  {
//  cout<<i<<' ';
  zap(i);
  //cout<<pa[i]<<endl;
  }
for (i=1; i<=1000; i++)
  if ((pa[i]==k-1)&&(i<=n))
    {
    //cout<<"I can by the "<<i<<endl;
    addc(n, i, 1);
    long ed=0;
    for (j=0; j<=n-1; j++)
      {
      if (s[j]=='1')
        ed++;
          else
          addc(n-j-1, i-ed-1, -1);
      }
    }
if (k==1)
  ans--;
while (ans<0)
  ans+=pc;
cout<<ans<<endl;
  return 0;
}