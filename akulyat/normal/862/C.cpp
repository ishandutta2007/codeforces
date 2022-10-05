#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j,x;
vector <ll> m;
bool viv=false;


int main()
{
cin>>n>>x;
j=ml-4;
if (n==2&&x==0)
  {
  cout<<"NO"<<endl;
  return 0;
  }
cout<<"YES"<<endl;
while (n>4&&(n!=6||x!=0))
  {
  cout<<j<<' ';
  cout<<j+1<<' ';
  cout<<j+2<<' ';
  cout<<j+3<<' ';
  n-=4;
  j-=4;
  }

if (n==6&&x==0)
  {
  cout<<"1 2 3 4 8 12 ";
  return 0;
  }

if (n==1)
  {
  cout<<x;
  return 0;
  }
if (n==2)
  {
  cout<<x<<' ';
  cout<<0<<' ';
  return 0;
  }

if (n==3)
  {
  cout<<(x^1)<<' ';
  cout<<100238<<' ';
  cout<<100239<<' ';
  return 0;
  }

if (n==4&&x==1)
  {
  cout<<"1 3 5 6 ";
  return 0;
  }

if (n==4)
  {
  cout<<1<<' ';
  cout<<x<<' ';
  cout<<100238<<' ';
  cout<<100239<<' ';
  return 0;
  }


    return 0;
}