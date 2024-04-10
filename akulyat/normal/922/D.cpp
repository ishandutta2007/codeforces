#include <bits/stdc++.h>

using namespace std;


const long sk=300100;

struct buk
{
  long long s;
  long long h;
};

bool cmp(buk a, buk b)
{
if ((a.h*b.s<b.h*a.s)||((a.h*b.s==b.h*a.s)&&((a.s>b.s)||(a.h<b.h))))
  return true; else
    return false;
}


long i,j,n,l;
long long ans=0;
string str;
long long kon[sk];
vector <buk> kol;



int main()
{
cin>>n;
getline(cin, str);
for (i=0; i<n; i++)
  {
  getline(cin, str);
  l=(long)str.size();
//  s.push_back(str);
  long ks=0;
  for (j=0; j<l; j++)
    if (str[j]=='s')
      ks++; else
        ans+=ks;
  buk d;
  d.s=ks;
  d.h=l-ks;
  kol.push_back(d);
  }


sort(kol.begin(), kol.end(), cmp);
kon[n-1]=kol[n-1].h;
  for (i=n-2; i>=0; i--)
    kon[i]=kon[i+1]+kol[i].h;

for (i=0; i<n-1; i++)
  ans+=kol[i].s*kon[i+1];
/*
                            for (i=0; i<n; i++)
                              cout<<kol[i].s<<' ';
                            cout<<endl;
                            for (i=0; i<n; i++)
                              cout<<kol[i].h<<' ';
                            cout<<endl;
*/
cout<<ans;
    return 0;
}