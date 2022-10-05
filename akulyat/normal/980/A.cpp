#include <bits/stdc++.h>

using namespace std;

struct block
{
  long z,p;
};

const long long k=1000;
const long long ml=k*k;
long long x1,x2,n,i,j;
vector <long long> gran;
vector <long> line;
vector <block> m;

bool cmp(block a, block b)
{
if (a.z<b.z)
  return true;
if (a.z==b.z&&a.p<b.p)
  return true;
return false;
}

long per(long a, long b)
{
long long x1=m[a].z;
long long x2=m[b].z;
if (x1==x2)
  return -ml*(k+1);

if ( (b*x2-a*x1)%(x2-x1)==0 )
  return (b*x2-a*x1)/(x2-x1);

  return (b*x2-a*x1)/(x2-x1)+1;
}

int main()
{

/*
cin>>n>>x1>>x2;

for (i=0; i<n; i++)
  {long a; cin>>a; m.push_back({a, i});}
sort(m.begin(), m.end(), cmp);
reverse(m.begin(), m.end());

gran.push_back(-ml*k);
line.push_back(0);
for (i=1; i<n; i++)
  {
  while (line.size()>1&&per(line.back(), i)<gran.back())
    {gran.pop_back(); line.pop_back();}
  gran.push_back(per(line.back(), i));
  line.push_back(i);
  }
gran.push_back(ml*k);

            /*
for (i=0; i<line.size(); i++)
  cout<<line[i]<<' ';
cout<<endl;
for (i=0; i<gran.size(); i++)
  cout<<gran[i]<<' ';
cout<<endl;
//            
j=n-1;
for (i=n-2; i>=0; i--)
  {
  long s1=m[i].z*(i+1);
  long s2;
  long p=upper_bound(gran.begin(), gran.end(), i)-gran.begin();
 // p--;
//  cout<<p<<'$'<<endl;
//  if (line[p]!=i)
//    p--;
  p=line[p];
  s2=m[p].z*(p-i);
  if (s1>=x1&&s2>=x2)
*/
    
    
    
    
    
    
  string s;
getline(cin, s);
long n;
n=s.size();
long k=0;
for (long i=0; i<n; i++)
  {
  if (s[i]=='o')
    k++;
  }
k=max(k, (long)1);
if ((n-k)%k==0)
  cout<<"Yes";
else
  cout<<"No";




    return 0;
}