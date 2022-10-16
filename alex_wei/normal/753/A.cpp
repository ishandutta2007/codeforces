#include <bits/stdc++.h>
using namespace std;
int k;
int main()
{
	cin>>k;
	for(int i=1;i<=k+1;i++)
		if(i*(i+1)/2>k){
			cout<<i-1<<endl;
			for(int j=1;j<i-1;j++)
				cout<<j<<" ",k-=j;
			cout<<k;
			exit(0);
		}
    return 0;
}