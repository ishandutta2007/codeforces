#include <bits/stdc++.h>

using namespace std;


const long kk=100*1000;
long n,m,k,s;
long i,j,u;
vector <long> reb[3*kk];
vector <long> all[3*kk];
vector <long> sum;
vector <long> t;
vector <long> st;
long col[200][3*kk];


int main()
{
cin>>n>>m>>s>>k;
for (i=0; i<n; i++)
  {
  long a;
  cin>>a;
  a--;
  t.push_back(a);
  }

for (i=0; i<m; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }

for (long c=0; c<s; c++)
  {
  st.clear();
  for (i=0; i<n; i++)
    col[c][i]=-1;
  for (i=0; i<n; i++)
    if (t[i]==c)
      {
      st.push_back(i);
      col[c][i]=0;
//      cout<<"col ["<<i<<']'<<'='<<c<<endl;
      }
  long s=0;
  while (s!=st.size())
    {
    long v=st[s];
    long l=reb[v].size();
    for (j=0; j<l; j++)
      if (col[c][reb[v][j]]==-1)
        {
        col[c][reb[v][j]]=col[c][v]+1;
        st.push_back(reb[v][j]);
        }
    s++;
    }
  }

/*
cout<<"OK"<<endl;
for (i=0; i<n; i++)
  {
  for (j=0; j<s; j++)
    cout<<col[j][i]<<' ';
  cout<<endl;
  }
*/
for (i=0; i<n; i++)
  {
  for (j=0; j<s; j++)
    all[i].push_back(col[j][i]);
  }

/*
cout<<"OK"<<endl;
for (i=0; i<n; i++)
  {
  for (j=0; j<s; j++)
    cout<<all[i][j]<<' ';
  cout<<endl;
  }
*/
for (i=0; i<n; i++)
  sort(all[i].begin(), all[i].end());

//cout<<"Sorted"<<endl;

for (i=0; i<n; i++)
  {
  sum.push_back(0);
  for (j=0; j<k; j++)
    {
//    cout<<i<<' '<<j<<endl;
    sum[i]+=all[i][j];
    }
  }
for (i=0; i<n; i++)
  cout<<sum[i]<<' ';

    return 0;
}