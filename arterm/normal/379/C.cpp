#include <iostream>
#include <algorithm>

using namespace std;

#define M 300300
#define f first
#define s second
#define mp make_pair

int n,ans[M];
pair<int,int> a[M];

void read(void){
	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>a[i].f;
		a[i].s=i;
	}
	sort(a,a+n);
}

void kill(void){
	int x=0;
	for (int i=0; i<n; ++i,++x){
		x=max(x,a[i].f);
		ans[a[i].s]=x;
	}
	for (int i=0; i<n; ++i)
	cout<<ans[i]<<" ";
}



int main()
{
	ios_base::sync_with_stdio(0);
	read();
	kill();
	return 0;
}