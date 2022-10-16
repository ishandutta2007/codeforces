#include<bits/stdc++.h>
using namespace std;
char a[100000],b[100000];
int main()
{
	cin>>a>>b;
	for(int i=0;i<strlen(a);i++){
		if(a[i]<'a')a[i]+=32;
		if(b[i]<'a')b[i]+=32;
	}
	cout<<strcmp(a,b);
    return 0;
}