	#include <iostream>
	#include <string>
	using namespace std;
	int main() {
		int n,s=0;
		string a;
		cin>>n>>a;
		int b[n];
		for(int i=0;i<n;i++){
			switch(a[i]){
				case 'F':b[i]=0; break;
				case 'S':b[i]=1; break;
			}
		}
		for(int i=0;i<n-1;i++){
			if(b[i]==0 && b[i+1]==1){
				s--;
			}
			if(b[i]==1 && b[i+1]==0){
				s++;
			}
		}
		if(s>0){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
		return 0;
	}