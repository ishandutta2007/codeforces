#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,k,i,j,a,b,did;
vector <ll> m;
bool viv=false;

bool ask(ll a, ll b)
{
did++;
cout<<a+1<<' '<<b+1<<endl;
string s;
cin>>s;
if (s=="Bad"||(a==b&&s=="Yes"))
  exit(0);
if (s=="Yes")
  return true;
if (s=="No")
  return false;
}

void jump()
{
a-=k;
b+=k;
a=max(a, 0ll);
b=min(b, n-1);
}

void sokr()
{
while ((b-a)>50)
  {
  ll mi=a+b>>1;
  if (ask(a, mi))
    b=mi;
  else
    a=mi;
  jump();
  }
}

void random()
{
ll p=rand()%(b-a+1)+a;
ask(p, p);
jump();
}



int main()
{
srand(time(0));
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;

a=0;
b=n-1;

did=0;
while (did<4470)
  {
  sokr();
  random();
  }





    return 0;
}