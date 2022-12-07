#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int q,d,a;
		cin>>q>>d;
		while(q--){
			scanf("%d",&a);
			long long b=a%10;if(b==0)b+=10;
			if((d%2||a%2==0)&&(d%5||a%5==0))while(b%d)b+=10;else b=a+1; 
			if(a>=b||a>=d*10)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
}