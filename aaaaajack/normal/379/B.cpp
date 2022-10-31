#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main(){
	int a[300],i,n;
	bool con=true,right=true;
	string s;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	i=0;
	while(con){
		con=false;
		if(right){
			while(i<n-1){	
				if(a[i]>0){
					con=true;
					s.push_back('P');
					a[i]--;
				}
				s.push_back('R');
				i++;
			}
			if(a[i]>0) con=true;
			right=false;
		}
		else{
			while(i>0){
				if(a[i]>0){
					con=true;
					s.push_back('P');
					a[i]--;
				}
				s.push_back('L');
				i--;
			}
			if(a[i]>0) con=true;
			right=true;
		}
	}
	cout<<s<<endl;
	return 0;
}