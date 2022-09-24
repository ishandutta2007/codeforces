#include <iostream>
#include <string>
using namespace std;
int main(){
	int n, i, r;
	r=0;
	int a[10000];
	int b[10000];
	string s;
	cin >> s;
	n= s.size();
	i=0;
	while (i<n){
		if (s[i]=='a'){
			a[i+1]=0;
		}
		else
		{
			a[i+1]=1;
		}
		if (i==0){
			b[0]=0;
			b[1]=a[1];
		}
		else
		{
			b[i+1]=b[i]+a[i+1];
		}
		
		i++;
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			int k;
			k=i-b[i]+b[j]-b[i]+n-j-b[n]+b[j];
			if (r<k){
				r=k;
			}
		}
		
	}
	cout << r;
}