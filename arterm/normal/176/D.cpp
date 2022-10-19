#include <iostream>
#include <string>
#include <vector>

#define M 2020
#define A 27
#define f first
#define s second
#define mp make_pair

using namespace std;

vector<int> t[M][A],id;
int n,m,l[M];
string h[M],s;
pair<int,int> d[M][M],link[M][A];

void read(void){
	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>h[i];
		l[i]=h[i].length();
		for (int j=0; j<A; ++j)
		t[i][j].resize(l[i]+1);
	}
	cin>>m;
	for (int i=0,x; i<m; ++i)
	cin>>x,id.push_back(x-1);
	cin>>s;
}

void pre(void){
	for (int i=0; i<n; ++i)
	for (int j=0; j<A; ++j){
		t[i][j][l[i]]=l[i];
		char ch='a'+j;
		
		for (int k=l[i]-1; k>=0; --k)
		if (h[i][k]==ch)
		t[i][j][k]=k;
		else
		t[i][j][k]=t[i][j][k+1];
	}
}

void links(void){
	for (int j=0; j<A; ++j){
		link[m][j]=mp(m,0);
		for (int i=m-1; i>=0; --i){
			int x=id[i];
			if (t[x][j][0]<l[x])
			link[i][j]=mp(i,t[x][j][0]);
			else
			link[i][j]=link[i+1][j];
		}
	}
}

pair<int,int> next(pair<int,int> p, int ch){
	int ts=p.f,tp=p.s+1;
	if (ts<m){
		int x=id[ts];
		tp=t[x][ch][tp];
		if (tp<l[x])
		return mp(ts,tp);
		tp=0;
		ts++;
	}
	return link[ts][ch];
}

void kill(void){
	int len=s.length();
	
	for (int i=0; i<=len; ++i)
	for (int j=0; j<=len; ++j)
	d[i][j]=mp(m,0);
	
	for (int i=0; i<=len; ++i)
	d[i][0]=mp(0,-1);
	
	for (int i=1; i<=len; ++i)
	for (int j=1; j<=i; ++j)
	d[i][j]=min(d[i-1][j],next(d[i-1][j-1],s[i-1]-'a'));
	
	int ans=0;
	for (int j=0; j<=len; ++j)
	for (int i=0; i<=len; ++i)
	if (d[i][j].f<m)
	ans=j;
	
	cout<<ans<<"\n";
}


int main()
{
	read();
	pre();
	links();
	kill();
	return 0;
}