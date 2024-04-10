#include<bits/stdc++.h>
using namespace std;
map <string,double> c;
int cnt,n,m,ex;
double k;
string s,t[44];
int main()
{
	cin>>n>>m>>k,k*=100;
	while(n--){cin>>s>>ex;if(ex*k>=10000)t[++cnt]=s,c[s]=ex*k/100.0;}
	while(m--){cin>>s;if(!c[s])t[++cnt]=s;}
	sort(t+1,t+cnt+1);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<t[i]<<" "<<(int)(c[t[i]]+0.001)<<endl;
	return 0; 
}