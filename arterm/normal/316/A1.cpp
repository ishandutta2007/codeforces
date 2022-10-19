#include <iostream>
#include <string>

#define M 100
#define long long long

using namespace std;

long l,a[M],n,t=0,k=0,b=0,c=0,ans=1;
string s;
bool u[M];

void read(void){
	cin>>s;
	n=s.length();
	for (int i=0; i<n; ++i){
		if (s[i]=='?')
		t++;
		if ('A'<=s[i] && s[i]<='J')
		if (!u[s[i]-'A']){
			u[s[i]-'A']=1;
			b++;
		}
		
	}
	
	if (s[0]=='?')
	--t,k=1;
	
	if ('A'<=s[0] && s[0]<='J')
	c=1,--b;
	
	
	if (k)
	ans=9;
	
	if (c==1){
		ans=9;
		for (int i=9; i>9-b; --i)
		ans*=i;
	}
	else{
		for (int i=10; i>10-b; --i)
		ans*=i;
	}
	
	cout<<ans;
	
	for (int i=0; i<t; ++i)
	cout<<0;
	cout<<"\n";
	
}

int main()
{
	read();
	return 0;
}