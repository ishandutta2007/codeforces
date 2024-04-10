#include <iostream>
#include <algorithm>
#include <vector>

#define M 100100
#define f first
#define s second
#define mp make_pair

using namespace std;

int n,k;
int t[4*M],s[M],d[M];
bool add[4*M];
vector<pair<int,int> > a[M];

void flip(int v, int l, int r, int le, int re){
	if (re<l || r<le || re<le)
	return;
	
	if (le<=l && r<=re){
		t[v]=r-l+1-t[v];
		add[v]^=1;
		return ;
	}
	int m=(l+r)/2;
	flip(2*v,l,m,le,re);
	flip(2*v+1,m+1,r,le,re);
	t[v]=t[2*v]+t[2*v+1];
	if (add[v])
	t[v]=r-l+1-t[v];
} 

int get(int v, int l, int r, int le, int re){
	if (re<l || r<le || re<le)
	return 0;
	
	int a=max(le,l);
	int b=min(r,re);
	
	if (b<a)
	return 0;
	
	if (a==l && b==r)
	return t[v];
	int m=(l+r)/2;
	
	int ans=get(2*v,l,m,a,b)+get(2*v+1,m+1,r,a,b);
	if (add[v])
	ans=b-a+1-ans;
	return ans;
}

void read(void){
	cin>>n>>k;
	for (int i=0; i<n; ++i)
	cin>>s[i];
	sort(s,s+n);
	for (int i=0,l,r; i<k; ++i){
		cin>>l>>r;
		l=(int)(lower_bound(s,s+n,l)-s);
		r=(int)(upper_bound(s,s+n,r)-s)-1;
		a[l].push_back(mp(l,r));
		a[r+1].push_back(mp(l,r));
	}
}

void kill(void){
	for (int i=0; i<n; ++i){
		for (int j=0; j<a[i].size(); ++j)
		flip(1,0,n-1,a[i][j].f,a[i][j].s);
		d[i]=get(1,0,n-1,0,i-1)+get(1,0,n-1,i+1,n-1);
		flip(1,0,n-1,i,i);
	}
	long long s=0;
	for (int i=0; i<n; ++i)
	s=s+1ll*d[i]*(d[i]-1)/2;
	s=1ll*n*(n-1)*(n-2)/6-s;
	cout<<s<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	read();
	kill();
	return 0;
}