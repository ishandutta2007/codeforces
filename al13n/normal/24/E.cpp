#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define forn(i,n) for(int i=0;i<n;++i)
#define forv(i,v) for(int i=0;i<v.size();++i)
#define pb push_back
#define lng long long
#define mp make_pair

double xs[1000000];
double vs[1000000];
pair<double,int> pos0[1000000];
vector<int> reqmax[500000];
vector<int> reqmin[500000];
int reqs;

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	forn(i,n){
		double x,v;
		cin>>x>>v;
		xs[i]=x;
		vs[i]=v;
		pos0[i]=mp(x,i);
	}
	sort(pos0,pos0+n);
	{
	int i=0;
	while(i<n){
		while(i<n&&vs[pos0[i].second]<0)
			++i;
		if(i==n)
			break;
		while(i<n&&vs[pos0[i].second]>0){
			reqmax[reqs].pb(pos0[i].second);
			++i;
		}
		if(i==n)
			break;
		while(i<n&&vs[pos0[i].second]<0){
			reqmin[reqs].pb(pos0[i].second);
			++i;
		}
		++reqs;
	}
	}

	double a=0,b=10000000000;
	bool sth=false;
	forn(q,80){
		double k=(a+b)/2;

		bool good=true;
		forn(q,reqs){
			double mn=10000000000,mx=-10000000000;
			forv(i,reqmax[q])
				mx=max(mx,xs[reqmax[q][i]]+vs[reqmax[q][i]]*k);
			forv(i,reqmin[q])
				mn=min(mn,xs[reqmin[q][i]]+vs[reqmin[q][i]]*k);
			if(mn<mx){
				good=false;
				break;
			}
		}
		if(!good){
			b=k;
			sth=true;
		}else
			a=k;
	}
	if(sth)
		printf("%.15lf",(a+b)/2);
	else
		cout<<-1;

	return 0;
}