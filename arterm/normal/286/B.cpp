#include <iostream>
#include <vector>
#include <algorithm>

#define long long long
#define M 2001000

using namespace std;

long  n,p[M];
vector<int> d,a;


void read(void){
	cin>>n;
	for (int i=0; i<n; ++i)
	p[i]=i;
	int k=0;
	for (int j=2; j<=n; ++j){
		d.clear();
		a.clear();
		a.push_back(0);
		for (int i=k; i<k+n; i+=j)
		d.push_back(p[i]),a.push_back(min((1ll*i+j),(k+n)));
		k++;
		for (int i=1; i<(int)a.size(); ++i)
		p[a[i]]=d[i-1];
	}
	for (int i=k; i<k+n; ++i,cout<<" ")
	cout<<p[i]+1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//pre();
	read();
	return 0;
}