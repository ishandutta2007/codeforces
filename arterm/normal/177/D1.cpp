#include <iostream>

#define M 100100

using namespace std;

int n,m,c,a[M],b[M],s[M];

void add(int &a, int b){
	a+=b;
	a%=c;
	if (a<0)
	a+=c;
}

void read(void){
	cin>>n>>m>>c;
	for (int i=1; i<=n; ++i)
	cin>>a[i];
	for (int j=1; j<=m; ++j)
	cin>>b[j];
}

void pre(void){
	for (int i=1; i<=m; ++i)
	add(s[i],s[i-1]),
	add(s[i],b[i]);
}

void kill(void){
	for (int i=1; i<=n; ++i){
		int l=1,r=m;
		r=min(m,i);
		l=max(l,(i-n+m));
		add(a[i],s[r]-s[l-1]);
	}
	for (int i=1; i<=n; ++i,cout<<" ")
	cout<<a[i];
	cout<<"\n";
}

int main()
{
	read();
	pre();
	kill();
	return 0;
}