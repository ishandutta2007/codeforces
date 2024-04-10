#include <bits/stdc++.h>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long n,i,j,u;
long sum=0,psum=0;
cin>>n;
long mini=100001;
long kol[3];
vector <long> mas;
kol[0]=0;
kol[1]=0;
kol[2]=0;
for (long i=0; i<n; i++)
  {
  long a; cin>>a;
  mas.push_back(a);
  if (a<mini)
    mini=a;
  }

 for (i=0; i<n; i++)
  {
    mas[i]-=mini; sum+=mas[i];
  }


for (i=0; i<n; i++)
  kol[mas[i] ]++;
long ans=-1;
long best=n+1;
for (long i=0; i<=n; i++)
  {
  long j,u;
  u=sum-(n-i);
  j=n-i-u;
  long per=0;
    per=min(i, kol[0])+min(j, kol[1])+min(u, kol[2]);
  if (((i>=0)&&(j>=0)&&(u>=0))&&(per<best)&&((u==0)||(kol[2]!=0)))
   { best=per; ans=i;}
  }


long a=ans,c=sum-(n-a),b=n-a-c;
cout<<best<<endl;
for (i=0; i<a; i++)
  cout<<mini<<' ';
for (i=0; i<b; i++)
  cout<<mini+1<<' ';
for (i=0; i<c; i++)
  cout<<mini+2<<' ';



    return 0;
}