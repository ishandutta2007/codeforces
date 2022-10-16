#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct card{
	int id,val;
}a[105];
bool cmp(card a,card b){return a.val<b.val;}
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].val,a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++)
		cout<<a[i].id<<" "<<a[n-i+1].id<<endl;
	return 0;
}