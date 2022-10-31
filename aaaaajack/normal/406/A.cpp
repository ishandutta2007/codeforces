#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
	int y,x;
	int n,q,t,i,j,ori=0;
	string s;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==i) scanf("%d",&y);
			else scanf("%d",&x);
		}
		if(y) ori^=1;
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&t);
		if(t==3) s.push_back('0'+ori);
		else{
			scanf("%d",&x);
			ori^=1;
		}
	}
	cout<<s<<endl;
	return 0;
}