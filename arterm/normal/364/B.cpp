#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define M 500400
#define long long long

int n,d,a[M],t[M];
bool u[M];
int q[M],st=0,fi=0;

void add(int x){
	for (int i=M-1; i>=x; --i)
		u[i]|=u[i-x];
}

void read(void){
	cin>>n>>d;
	for (int i=0; i<n; ++i)
		cin>>a[i];
	sort(a,a+n);
}

void kill(void){
	u[0]=1;

	int m=0,s=0;
	while (m<n && s+d>=a[m]){
		s+=a[m];
		add(a[m]);
		m++;
	}

	t[s]=0;

	q[fi++]=s;
	for (int i=s-1; i>=0; --i)
		if (u[i]){
			while (q[st]>i+d)
				st++;
			t[i]=t[q[st]]+1;
			q[fi++]=i;
		}

	cout<<s<<" "<<t[0]<<"\n";
			
}

int main(){
#ifdef HOMEMOD
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#else
	ios_base::sync_with_stdio(0);
#endif
	read();
	kill();

	return 0;
}