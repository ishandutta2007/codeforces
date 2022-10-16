#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mon puts("Monocarp")
#define bic puts("Bicarp")
int n,a,a1,a2,q1,q2;
string s;
int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='?')i>n/2?q2++:q1++;
		else a=s[i-1]-'0',i>n/2?a2+=a:a1+=a;
	}
	int dif1=a1-a2,dif2=dif1,r1=q1,r2=q2;
	int pd=1;
	while(q2){q2--;if(!pd)dif1-=9;pd=!pd;}
	while(q1){q1--;if(pd)dif1+=9;pd=!pd;}
	if(dif1<0)mon,exit(0);
	pd=1;
	while(r1){r1--;if(pd)dif2+=9;pd=!pd;}
	while(r2){r2--;if(!pd)dif2-=9;pd=!pd;}
	if(dif2>0)mon,exit(0);
	bic;
    return 0;
}