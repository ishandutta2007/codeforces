#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,a,b;
int main()
{
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a>=b){puts("yes");continue;}
		if(a==1&&b>1){puts("no");continue;}
		while(a){
			if(a%2){
				if(a==3&&b>3){puts("no");break;}
				a--;
			}
			else a=a*3/2;
			if(a>=b){puts("yes");break;}
		}
	}
    return 0;
}