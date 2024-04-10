#include <iostream>
#include <map>
#include <algorithm>

#define f first
#define s second
#define mp make_pair
#define M 200100

using namespace std;

int n,m,k,d,x,h=0;
pair<int,int> a[M];

void read(void){
	cin>>n>>m>>k;
	for (int i=0,x; i<n; ++i){
		cin>>x;
		a[h++]=mp(x,1);
	}
	for (int i=0,x; i<m; ++i){
		cin>>x;
		a[h++]=mp(x,-1);
	}
}

bool kill(void){
	sort(a,a+h);
	int t=0;
	for (int i=h-1; i>=0;){
		int j=i;
		while (j>=0 && a[i].f==a[j].f)
		t+=a[j].s,j--;
		if (t>0)
		return 1;
		i=j;
	}
	return 0;
}

int main()
{
	read();
	cout<<(kill() ? "YES":"NO")<<"\n";
	return 0;
}