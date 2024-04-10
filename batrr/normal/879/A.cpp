#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	int n,d,s,now=0,j;
	cin>>n>>d>>s;
	now=d;
	for(int i=1;i<n;i++){
		cin>>d>>s;
		while(d<=now)d+=s;
		//cout<<j<<" ";
		now=d;
	}
	cout<<now; 
	return 0;
}