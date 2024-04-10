#include<bits/stdc++.h>
using namespace std;
long long a,b,k,pos=1;
int main()
{
	cin>>a>>b;
	while(k<=b){
		long long minus=(a/pos)%10;
		if(minus==9){pos*=10;continue;}
		else minus=(minus+1)*pos;
		pos*=10;
		if(k+minus<=b)a-=minus,k+=minus;
		else break;
	}
	cout<<a;
    return 0;
}