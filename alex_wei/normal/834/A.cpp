#include<bits/stdc++.h>
using namespace std;
string d="^>v<";
int n;
char a,b;
int main()
{
	cin>>a>>b>>n,n%=4;
	for(int i=0;i<4;i++)
		if(a==d[i]){
			if(d[(i+n)%4]==b&&d[(i-n+4)%4]!=b)cout<<"cw",exit(0);
			if(d[(i+n)%4]!=b&&d[(i-n+4)%4]==b)cout<<"ccw",exit(0);
		}
	cout<<"undefined";
	return 0;
}