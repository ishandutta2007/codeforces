#include<bits/stdc++.h>
using namespace std;
int n;
string s;
void print(int x)
{
	if(x==0)return;
	print((x-1)/26);
	cout<<(char)((x-1)%26+'A');
}
int main()
{
	cin>>n;
	for(int l=0;l<n;l++){
		cin>>s;
		int pd=0;
		for(int i=1;i<s.size();i++)
			if(s[i]>'9'&&s[i-1]<='9')
				pd=1;
		if(pd){
			int a=0,b=0,j=1;
			for(;s[j]<='9';j++)
				a=a*10+(s[j]-'0');
			for(j=j+1;j<s.size();j++)
				b=b*10+(s[j]-'0');
			print(b);
			cout<<a<<endl;
		}
		else{
			int a=0,b=0,j=0;
			for(;s[j]>'9';j++)
				a=a*26+s[j]-'A'+1;
			for(;j<s.size();j++)
				b=b*10+s[j]-'0';
			printf("R%dC%d\n",b,a);
		}
	}
    return 0;
}