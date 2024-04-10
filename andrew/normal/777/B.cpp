#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
using namespace std;
ll a[1000000],b[100000],v[100000],i,j,n,m,k,sc,mx,mn,l,r;
string s,s1,s2;
char c,c1,c2;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
for(i=0;i<n;i++)
{
    cin >> c;
    a[i]=c-48;
}
for(i=0;i<n;i++)
{
    cin >> c;
    b[i]=c-48;
    b[i+n]=b[i];
}
sort(a,a+n);
sort(b,b+n);
for(i=0;i<n;i++)
{
    ll fl=-1;
    for(j=0;j<n;j++)if(b[j]>a[i] and v[j]==0){fl=j;break;}
    if(fl!=-1)
    {
       v[fl]=1;
       sc++;
       continue;
    }
}
for(i=0;i<n;i++)v[i]=0;

for(i=0;i<n;i++)
{
    ll fl=-1;
    for(j=0;j<n;j++)if(b[j]>=a[i] and v[j]==0){fl=j;break;}
    if(fl!=-1)
    {
       v[fl]=1;
       continue;
    }
    for(j=0;j<n;j++)if(b[j]<a[i] and v[j]==0){fl=j;break;}
    v[fl]=1;
    m++;
}
 cout << m << endl << sc << endl;
  return 0;
}