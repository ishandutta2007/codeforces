#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[100];

int main()
{
	string s;
	int i,arr[6],a=0,b=0,m,j;
	cin >> s;
	for(i=0;i<6;i++) arr[i]=s[i]-'0';
	for(i=0;i<3;i++) a+=arr[i],b+=arr[i+3];
	if(a>b)
		for(i=3,m=a-b;i<6;i++) arr[i]=9-arr[i];
	else 
		for(i=0,m=b-a;i<3;i++) arr[i]=9-arr[i];
	sort(arr,arr+6);
	for(i=5;i>=0 && m>0;i--)
		m-=arr[i];
	printf("%d\n",5-i);
}