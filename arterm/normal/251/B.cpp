#include <iostream>

#define M 121

using namespace std;

int n,k;

struct pt{
	int a[M];
	void ini(void){
		for (int i=0; i<M; ++i)
		a[i]=i;
	}
	void read(void){
		for (int i=1; i<=n; ++i)
		cin>>a[i];
	}
} q,s,a;

pt operator * (pt a, pt b){
	pt c;
	for (int i=1; i<=n; ++i)
	c.a[i]=a.a[b.a[i]];
	return c;
}

pt rev(pt a){
	pt b;
	for (int i=1; i<=n; ++i)
	b.a[a.a[i]]=i;
	return b;
}

bool operator !=(pt a, pt b){
	for (int i=1; i<=n; ++i)
	if (a.a[i]!=b.a[i])
	return 1;
	return 0;
}

void read(void){
	cin>>n>>k;
	q.read();
	s.read();
}

bool kill(void){
	a.ini();
	int l=0,r=0;
	while (l<=k && a!=s)
	a=a*q,l++;
	
	a.ini();
	q=rev(q);
	while (r<=k && a!=s)
	a=a*q,r++;
	
	if (l==k || r==k)
	return 1;
	
	if (l<=k && (r>=2 || l>=2) && l%2==k%2)
	return 1;
	
	if (r<=k && (r>=2 || l>=2) && r%2==k%2)
	return 1;
	
	
	return 0;
	
}

int main()
{
	read();
	cout<<(kill() ? "YES\n":"NO\n");
	return 0;
}