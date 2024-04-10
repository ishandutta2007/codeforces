#include<bits/stdc++.h>
using namespace std;
long long n,k,s,c[26],j=25;
string p;
int main()
{
	cin>>n>>k>>p;
	for(int i=0;i<p.size();i++)
		c[p[i]-'A']++;
	sort(c,c+26);
	while(k){
		long long mi=min(k,c[j]);
		s+=mi*mi;
		k-=mi,j--;
	}
	cout<<s;
	return 0;
}