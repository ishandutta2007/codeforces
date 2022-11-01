#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll a,b,c;
int main()
{
	cin>>a>>b>>c;
	if(a==b && b==0 && c==0)return cout<<-1,0;
	if(a==0 && b==0)return cout<<0,0;
	if(a==0)return cout<<"1\n"<<fixed<<setprecision(14)<<(ld)-c/(ld)b,0;
	
	ld delta=b*b-4*a*c;
	if(delta<0)return cout<<0,0;
	if(delta==0)return cout<<"1\n"<<fixed<<setprecision(14)<<((ld)-b/((ld)2*a)),0;
	cout<<"2\n";	
	ld sqr=(ld)sqrt((ld)delta);
	ld a1=((ld)-b-(ld)sqr)/((ld)a*2);
	ld a2=((ld)-b+(ld)sqr)/((ld)a*2);
	if(a1>a2)swap(a1,a2);
	cout<<setprecision(14)<<fixed<<(ld)a1<<"\n"<<(ld)a2;			
    return 0;
}