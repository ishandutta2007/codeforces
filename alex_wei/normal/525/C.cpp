#include<bits/stdc++.h>
using namespace std;
long long n,a[100002],s,cp;
bool cmp(int x,int y){return x>y;}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n-1;i++)
		if(a[i]-a[i+1]<2){
			if(!cp)cp=a[i+1];
			else s+=cp*a[i+1],cp=0;
			i++;
		}
	cout<<s;
	return 0;
}