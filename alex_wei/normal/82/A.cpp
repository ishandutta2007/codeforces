#include<bits/stdc++.h>
using namespace std;
int n,p=5,s;
map <int,string> c;
int main()
{
	cin>>n,n--;
	if(n<5)s=n;
	else{while(n>=p)n-=p,p*=2;s=n/(p/5);}
	c[0]="Sheldon",c[1]="Leonard",c[2]="Penny",c[3]="Rajesh",c[4]="Howard";
	cout<<c[s];
}