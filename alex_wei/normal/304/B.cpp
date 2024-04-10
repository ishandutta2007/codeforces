#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,m[12]={31,28,31,30,31,30,31,31,30,31,30,31},ans;
char n;
int main()
{
	cin>>a>>n>>b>>n>>c>>d>>n>>e>>n>>f;
	if(a>d||(a==d&&b>e)||(a==d&&b==e&&c>=f))swap(a,d),swap(b,e),swap(c,f);
	while(a!=d||b!=e||c!=f){
		if(a%4==0&&a%100!=0||a%400==0)m[1]=29;
		else m[1]=28;
		ans++,c++;
		if(c>m[b-1])c=1,b++;
		if(b>12)b=1,a++;
	}
	cout<<ans;
    return 0;
}