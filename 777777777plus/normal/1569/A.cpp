#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
int n;
string s;

int main(){
	cin>>T;
	while(T--){
		cin>>n>>s;
		for(int i=0;i<n;++i)
		for(int j=i;j<n;++j){
			int c=0;
			for(int k=i;k<=j;++k){
				if(s[k]=='a')++c;
				else --c;
			}
			if(!c){
				cout<<i+1<<" "<<j+1<<endl;
				goto die;
			}
		}
		cout<<-1<<" "<<-1<<endl;
		die:;
	}
}