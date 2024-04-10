#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define M 500200

int n,m,a[M],b[M],p,all[M],f[M],ti[M],tim=0,z,r[M],zer=0;
vector<int> ans;

void read(void){
	cin>>n>>m>>p;
	int c=0;
	for (int i=0; i<n; ++i)
		cin>>a[i],
		all[c++]=a[i];
	for (int i=0; i<m; ++i)
		cin>>b[i],
		all[c++]=b[i];

	sort(all,all+c);
	for (int i=0; i<n; ++i)
		a[i]=lower_bound(all,all+c,a[i])-all;
	for (int i=0; i<m; ++i)
		b[i]=lower_bound(all,all+c,b[i])-all;
}

void pre(void){
	for (int i=0; i<m; ++i)
		f[b[i]]++;
	for (int i=0; i<M; ++i)
		if (f[i]!=0)
			zer++;
}

void add(int x, int v){
	if (ti[x]<tim)
		ti[x]=tim,r[x]=f[x];

	if (r[x]==0)
		z++;

	r[x]-=v;

	if (r[x]==0)
		z--;
}


void kill(void){
	for (int i=0; i<p && i<n; ++i){
		tim++;
		z=zer;
		int j=i,k=0;
		for (; k<m && j<n; j+=p,k++)
			add(a[j],1);

		while (true){
			if (z==0)
				ans.push_back(j-p*m+1);
			if (j>=n)
				break;
			add(a[j-p*m],-1);
			add(a[j],1);
			j+=p;
		}
	}
	

	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for (int i=0; i<ans.size(); ++i)
		cout<<ans[i]<<" ";
	cout<<"\n";
}

int main(){
#ifdef TROLL
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#else
	ios_base::sync_with_stdio(0);
#endif

	read();
	pre();
	kill();

	return 0;
}