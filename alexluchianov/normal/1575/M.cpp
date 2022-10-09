#include <bits/stdc++.h>
using namespace std;

#define int long long

struct func{
		int a, b;
		int value(int x){
				return a*x+b;
		}
};

double intersect(func x, func y){
	return (x.b-y.b)/(y.a-x.a);
}

bool check(func x, func y, func z){
	return (y.b-x.b)*(x.a-z.a)>(x.a-y.a)*(z.b-x.b);
}

int n, m;
bool a[2003][2003];
int dmin[2003][2003];

int32_t main(){
	cin.tie(0);
	ios_base::sync_with_stdio();
	cin>>n>>m;
	n++, m++;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			char x;
			cin>>x;
			a[i][j]=(x=='1');
			dmin[i][j]=1e18;
		}
	}
	vector<int> last(m+1, 0);
	for(int i=1;i<=n;++i){
		vector<func> v(0);
		vector<func> s(0);
		for(int j=1;j<=m;++j){
			if(a[i][j]) last[j]=i;
			if(last[j]){
				int xp=last[j], yp=j;
				func val={-2*yp, xp*xp+yp*yp-2*xp*i};
				v.push_back(val);	
			}
		}
		if(!v.size()) continue;
		s.push_back(v[0]);
		for(int j=1;j<v.size();++j){
			if(v[j].a!=v[j-1].a){
				while(s.size()>1&&check(s[s.size()-2], s[s.size()-1], v[j])) s.pop_back();
				s.push_back(v[j]);
			}
		}
		int cr=0;
		for(int j=1;j<=m;++j){
			while(cr<(s.size()-1)&&s[cr].value(j)>s[cr+1].value(j)) cr++;
			dmin[i][j]=min(dmin[i][j], s[cr].value(j)+i*i+j*j);
		}
	}
	for(int j=1;j<=m;++j) last[j]=0;
	for(int i=n;i;--i){
		vector<func> v;
		vector<func> s;
		for(int j=1;j<=m;++j){
			if(a[i][j]) last[j]=i;
			if(last[j]){
				int xp=last[j], yp=j;
				func val={-2*yp, xp*xp+yp*yp-2*xp*i};
				v.push_back(val);	
			}
		}
		if(!v.size()) continue;
		s.push_back(v[0]);
		for(int j=1;j<v.size();++j){
			if(v[j].a!=v[j-1].a){
				while(s.size()>1&&check(s[s.size()-2], s[s.size()-1], v[j])) s.pop_back();
				s.push_back(v[j]);
			}
		}
		int cr=0;
		for(int j=1;j<=m;++j){
			while(cr<(s.size()-1)&&s[cr].value(j)>s[cr+1].value(j)) cr++;
			dmin[i][j]=min(dmin[i][j], s[cr].value(j)+i*i+j*j);
		}
	}
	int lastpoz=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!a[i][j]) continue;
			if(lastpoz) dmin[i][j]=min(dmin[i][j], (j-lastpoz)*(j-lastpoz));
			lastpoz=j;
		}
		lastpoz=0;
		for(int j=m;j;--j){
			if(!a[i][j]) continue;
			if(lastpoz) dmin[i][j]=min(dmin[i][j], (lastpoz-j)*(lastpoz-j));
			lastpoz=j;
		}
	}
	int sum=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			sum+=dmin[i][j];
		}
	}
	cout<<sum<<"\n";
}