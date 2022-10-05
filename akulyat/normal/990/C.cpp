#include <bits/stdc++.h>

using namespace std;

long long n,i,j;;
long long r,ans;
vector <string> s;
vector <long long> mn,pl;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

cin>>n;
for (i=0; i<n; i++)
  {string ss; cin>>ss; s.push_back(ss); }

for (i=0; i<n; i++)
  {
  long long l=s[i].size();
  long long cur=0;
  long long mini=0;
  for (long long j=0; j<l; j++)
    {
    if (s[i][j]=='(')
      cur++;
    else
      cur--;
    mini=min(mini, cur);
    }
  if (cur==0)
    {
    if (mini==0)
      r++;
    }
  else
    {
    if (cur>0&&mini>=0)
      pl.push_back(cur);
    if (cur<0&&mini==cur)
      mn.push_back(-cur);
    }
  }
ans+=r*r;
sort(pl.begin(), pl.end());
sort(mn.begin(), mn.end());
//cout<<"It is r="<<r<<endl;
long long l1=pl.size();
long long l2=mn.size();
/*
for (i=0; i<l1; i++)
  cout<<pl[i]<<' ';
cout<<endl;
for (i=0; i<l2; i++)
  cout<<mn[i]<<' ';
cout<<endl;
*/
i=0;
j=0;
while (i<l1&&j<l2)
  {
  while (pl[i]<mn[j]&&i<l1)
    i++;
  if (i<l1)
    while (mn[j]<pl[i]&&j<l2)
      j++;
  if (i<l1&&j<l2)
    if (pl[i]==mn[j])
      {
      long long i1=i;
      long long j1=j;
      while (i1<l1&&pl[i]==pl[i1])
        i1++;
      while (j1<l2&&mn[j]==mn[j1])
        j1++;
      ans+=(i1-i)*(j1-j);
      i=i1;
      j=j1;
      }
  }

cout<<ans;


    return 0;
}