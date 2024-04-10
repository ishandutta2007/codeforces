#include <bits/stdc++.h>

using namespace std;

long long n,k,i;
string s;
long long m[3][300000];
long long put[300000];


int main()
{
cin>>n>>k>>s;
for (i=0; i<n; i++)
  {
  if (s[i]!='.')
    {
    m[s[i]-'0'][i%k]=1;
    }
  else
    m[2][i%k]++;
  }

bool z=false;
for (i=0; i<k; i++)
  if ((m[0][i%k]*m[1][i%k]>0)||((m[0][i%k]+m[1][i%k])*m[2][i%k]>0)||(m[2][i%k]>1))
    {
    z=true;
    }

if (z==false)
  {
  cout<<"No"<<endl;
  return 0;
  }


for (i=0; i<n; i++)
  {
  if (s[i]!='.')
    cout<<s[i];
  else
    {
    if ((m[0][i%k]*m[1][i%k]>0)||((m[0][i%k]+m[1][i%k])*m[2][i%k]>0)||(m[2][i%k]>1))
      {
      if (m[0][i%k]!=0)
        cout<<1;
      else
        {
        if (m[1][i%k]!=0)
          cout<<0;
        else
          {
          if (put[i%k]==0)
            {
            cout<<1;
            put[i%k]=1;
            }
          else
            cout<<0;
          }
        }
      }
    else
      {
      cout<<1;
      }
    }
  }


    return 0;
}