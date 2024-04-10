#include<bits/stdc++.h>
using namespace std;
#define ababa abababa
int w,h;
char a[102][102],b[102][102];
int main()
{
	cin>>w>>h;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			cin>>a[i][j];
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			b[j][h-i+1]=a[i][j];
	for(int i=1;i<=w;i++)
		reverse(b[i]+1,b[i]+h+1);
	for(int i=2;i<=2*w+1;i++){
		for(int j=2;j<=2*h+1;j++)
			cout<<b[i/2][j/2];
		cout<<endl;
	}
	return 0;
}