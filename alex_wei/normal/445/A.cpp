#include<bits/stdc++.h>
using namespace std;
int n,m;
char s;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>s;
			if(s=='.')
				s=((i+j)%2?'W':'B');
			cout<<s;
		}
		cout<<endl;
	}
	return 0;
}