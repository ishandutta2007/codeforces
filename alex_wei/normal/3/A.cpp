#include<bits/stdc++.h>
using namespace std;
string a,b; 
int main()
{
	cin>>a>>b;
	cout<<max(abs(a[0]-b[0]),abs(a[1]-b[1]))<<endl;
	while(a!=b){
		if(a[0]>b[0])cout<<"L",a[0]--;
		if(a[0]<b[0])cout<<"R",a[0]++;
		if(a[1]>b[1])cout<<"D",a[1]--;
		if(a[1]<b[1])cout<<"U",a[1]++;
		cout<<endl;
	}
    return 0;
}