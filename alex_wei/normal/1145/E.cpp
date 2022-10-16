#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int k=21;k<=50;k++)
		cout<<((min(k,25)+k)%(2+k%3)>0)<<endl;
	return 0;
}