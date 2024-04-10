#include<bits/stdc++.h>
using namespace std;
int pw[50],a,b,c,cnt;
int main(){
	pw[0]=1;
	for(cnt=1;pw[cnt-1]<=7e8;cnt++)pw[cnt]=pw[cnt-1]*3;
	cin>>a>>c;
	for(int i=0;i<cnt;i++){
		int x=a/pw[i]%3,y=c/pw[i]%3;
		if(y<x)y+=3;
		b+=pw[i]*(y-x);
	}
	cout<<b<<endl;
    return 0;
}