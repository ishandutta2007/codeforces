#include<bits/stdc++.h>
using namespace std;
int a,b,w,d,l;
int main()
{
	cin>>a>>b;
	for(int i=1;i<7;i++){
		if(abs(a-i)>abs(b-i))l++;
		else if(abs(a-i)==abs(b-i))d++;
	else w++;
	}
	cout<<w<<" "<<d<<" "<<l; 
	return 0;
}