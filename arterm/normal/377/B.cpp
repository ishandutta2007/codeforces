#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define M 100100
#define f first
#define s second
#define mp make_pair

int n,m,s;
pair<int,int> a[M];
pair<pair<int,int>,int> p[M];
int ans[M];

void read(void){
	cin>>n>>m>>s;
	for (int i=0; i<m; ++i){
		cin>>a[i].f;
		a[i].s=i;
	}
	
	for (int i=0; i<n; ++i)
	cin>>p[i].f.f;
	
	for (int i=0; i<n; ++i)
	cin>>p[i].f.s;
	
	for (int i=0; i<n; ++i)
	p[i].s=i+1;
	
	
	sort(p,p+n);
	sort(a,a+m);
}

bool pos(int k){
	priority_queue<int> q;
	int i=n-1,j=m-1,t=0;
	while (j>=0){
		while (i>=0 && p[i].f.f>=a[j].f){
			q.push(-p[i].f.s);
			--i;

		}
		
		if (q.empty())
		return 0;
		
		t=t-q.top();
		q.pop();
		
		if (t>s)
		return 0;
		
		j-=k;
	}
	return 1;
}

void print(int k){
	cout<<"YES\n";
	
	priority_queue<pair<int,int> > q;
	
	int i=n-1,j=m-1;
	while (j>=0){
		while (i>=0 && p[i].f.f>=a[j].f){
			q.push(mp(-p[i].f.s,p[i].s));
			--i;
		}
		
		for (int h=0; h<k && j>=0; ++h,--j)
			ans[a[j].s]=q.top().s;
		
		q.pop();
	}
	
	for (int i=0; i<m; ++i)
	cout<<ans[i]<<" ";
}

void bin(void){
	int l=0,r=1000000100,m;
	while (l<r){
		m=(l+r)/2;
		if (pos(m))
		r=m;
		else
		l=m+1;
	}
	if (!pos(l))
	cout<<"NO\n";
	else
	print(l);
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	bin();
	return 0;
}