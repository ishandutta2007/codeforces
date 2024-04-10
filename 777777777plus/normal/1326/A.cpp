#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T;
int n;

int main(){
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		int re3=0,re7=0;
		for(int i=1;i<=n-2;++i){
			re3=(re3*10+2)%3;
			re7=(re7*10+2)%7;
			cout<<2;
		}
		re3=re3*100%3;
		re7=re7*100%7;
		for(int i=2;i<=9;++i)
		if((re3+i*10+7)%3&&(re7+i*10+7)%7){
			cout<<i<<7<<endl;
			break;
		}
	}
}