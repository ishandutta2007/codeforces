#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[6],s,ss;
bool used[6];
bool x(int b){
	if(b==0){
		if(ss==s-ss)
			return true;
		else
			return false;
	}else{
		for(int i=0;i<6;i++){
			if(used[i]==false){
				used[i]=true;
				ss+=a[i];
				if(x(b-1)==true)
					return true;
				used[i]=false;
				ss-=a[i];
			}
		}
		return false;
	}
}
int main(){
	for(int i=0;i<6;i++){
		cin>>a[i];		
		s+=a[i];
	}
	if(x(3)==true)
		cout<<"YES";
	else
		cout<<"NO";
}