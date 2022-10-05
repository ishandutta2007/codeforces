#include <bits/stdc++.h>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
vector <long> mas,tos;
long n,i,j,u;
string s;
const long z=300000;
long st[z],fi[z];
cin>>n;
for (i=0; i<n; i++)
  {
  long a;
  cin>>a;
  mas.push_back(a);
  }
getline(cin,s);
getline(cin,s);

st[0]=0;
fi[n-1]=n-1;
for (i=1; i<n; i++)
  if (s[i-1]=='1')
    st[i]=st[i-1]; else
      st[i]=i;
for (i=n-2; i>=0; i--)
  if (s[i]=='1')
    fi[i]=fi[i+1]; else
      fi[i]=i;

for (i=0; i<n; i++)
  {
//  long pos=*lower_bound(tos.begin(), tos.end(), mas[i]);
  long ch=mas[i]-1;
  if ((ch>fi[i])||(ch<st[i]))
    {
//    cout<<i<<' '<<ch<<endl;
    cout<<"NO";
    return 0;
    }
  }
cout<<"YES";
    return 0;
}