#include<bits/stdc++.h>
using namespace std;
#define ll long long
int k,t[10];
char c;
int main()
{
	cin>>k;
	for(int i=0;i<16;i++){
		cin>>c;
		if(c!='.')t[c^48]++;
	}
	for(int i=1;i<10;i++)
		if(t[i]>2*k)cout<<"NO",exit(0);
	cout<<"YES";
	return 0;
}