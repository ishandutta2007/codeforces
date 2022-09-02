#include<iostream>
#include<cstdio>
using namespace std;


int main()
{
int n;
cin>>n;
long long sum = 0;
long long a;
for (int i = 0; i<n; i++) {cin>>a; sum+=a;}
long long max1, max2;
cin>>max1>>max2;
for (int i = 2; i<n; i++)
{
   if (max1<max2) swap(max1, max2);
   cin>>a;
   max2 = max(max2, a);
}
if (max1+max2>=sum) cout<<"YES";
else cout<<"NO";
//cout<<endl<<sum<<' '<<max1<<' '<<max2;


}