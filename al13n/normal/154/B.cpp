#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <queue>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-11
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev

int src[110000];
bool unprime[110000];
int coll[110000];
bool on[110000];

vector<int> factor(int a){
	vector<int> res;
	for(int i=2;i*i<=a;++i){
		if(a%i)
			continue;
		res.pb(i);
		while(a%i==0)
			a/=i;
	}
	if(a>1)
		res.pb(a);
	return res;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);

	int n,m;
	cin>>n>>m;
	
	forn(i,m){
		char ch;
		int a;
		cin>>ch>>a;
		vector<int> f=factor(a);
		if(ch=='-'){
			if(!on[a]){
				cout<<"Already off";
			}else{
				cout<<"Success";
				on[a]=false;
				forv(j,f){
					coll[f[j]]=0;
				}
			}
		}else{
			if(on[a]){
				cout<<"Already on";
			}else{
				int con=0;
				forv(j,f){
					con=max(con,coll[f[j]]);
				}
				if(con){
					cout<<"Conflict with "<<con;
				}else{
					cout<<"Success";
					on[a]=true;
					forv(j,f){
						coll[f[j]]=a;
					}
				}
			}
		}
		cout<<"\n";
	}

    return 0;
}