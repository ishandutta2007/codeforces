#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a,b,c,d;
bool check(){return a==d&&b==c;}
void update(){
	if(d>'9')d='0',c++;
	if(c>'5')c='0',b++;
	if(a<'2'&&b>'9')b='0',a++;
	if(a>'1'&&b>'3')a='0',b='0';
}
int main()
{
	cin>>a>>b>>c>>c>>d;
	d++,update();
	while(!check())d++,update();
	cout<<a<<b<<":"<<c<<d; 
	return 0;
}