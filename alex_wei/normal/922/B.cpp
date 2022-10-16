#include<bits/stdc++.h>
using namespace std;
int s,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			int k=i xor j;
			if(k>=j&&i+j>k&&k<=n)
				s++;
		}
	cout<<s;
	return 0;
}