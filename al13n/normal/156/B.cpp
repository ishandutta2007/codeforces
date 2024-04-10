#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define dinf 1e200
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
#define ends asdends
#define PII pair<int,int> 
#define X first
#define Y second
#define mset(a,b) memset(a,b,sizeof(a))

int src[110000];
int cnt[110000];
bool can[110000];
int add;
int n,m;

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(false);

	cin>>n>>m;
	forn(i,n){
		int a;
		cin>>a;
		src[i]=a;
		if(a>0){
			++cnt[a-1];
		}else{
			++add;
			--cnt[-a-1];
		}
	}
	int c=0;
	forn(i,n){
		can[i]=cnt[i]+add==m;
		if(can[i])
			++c;
	}
	forn(i,n){
		int a=src[i];
		int p=abs(a)-1;
		if(a>0){
			if(!can[p])
				cout<<"Lie";
			else if(c>1)
				cout<<"Not defined";
			else
				cout<<"Truth";
		}else{
			if(!can[p])
				cout<<"Truth";
			else if(c>1)
				cout<<"Not defined";
			else
				cout<<"Lie";
		}
		cout<<'\n';
	}

	return 0;
}