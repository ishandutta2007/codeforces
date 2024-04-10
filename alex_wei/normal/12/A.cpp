#include<bits/stdc++.h>
using namespace std;
char c[10]; 
int main()
{
	for(int i=1;i<10;i++)cin>>c[i];
	cout<<(c[1]==c[9]&&c[2]==c[8]&&c[3]==c[7]&&c[4]==c[6]?"YES":"NO");
	return 0;
}