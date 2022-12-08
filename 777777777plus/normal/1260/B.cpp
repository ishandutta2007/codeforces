#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T,a,b;

int main(){
	cin>>T;
	while(T--){
		cin>>a>>b;
		if(a>b)swap(a,b);
		if(a==b){
			if(a%3==0)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else if(b>2*a){
			cout<<"NO"<<endl;
		}
		else{
			int t=b-a;
			a-=t;b-=2*t;
			if(a%3==0)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	
}