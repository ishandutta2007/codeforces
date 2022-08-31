#pragma comment(linker,"/STACK:256000000")
#include <vector>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <complex>
#ifdef __ASD__
//#include <windows.h>
#endif
using namespace std;
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<(n);++i)
#define fornn(i,n) for(i=0;i<(n);++i)
#define lng long long
#define SQ(a) ((a)*(a))
#define forv(i,v) for(int i=0;i<(int)v.size();++i)
#define mp make_pair
#define pb push_back
#define ABS(a) ((a)<0?-(a):(a))
#define iinf 1000000000
#define linf 1000000000000000000LL
#define dinf 1e200
#define left asdleft
#define prev asdprev
#define eps 1e-12
#define y1 asdy1
#define y2 asdy2
#define EQ(a,b) abs((a)-(b))<eps
#define PI 3.1415926535897932384626433832795
#define DEG2RAD PI/180
#define ulng unsigned lng
#define next asdnext
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
void mytimer(string task){
#ifdef __ASD__
        //static LARGE_INTEGER prev;      LARGE_INTEGER cur,freq; QueryPerformanceCounter(&cur);  QueryPerformanceFrequency(&freq);       if(task!="")            cout<<task<<" took "<<(cur.QuadPart-prev.QuadPart)*1.0/freq.QuadPart<<endl;     prev=cur;
#endif
}
void ext(int c){
#ifdef __ASD__
        exit(c);
#endif
}

struct node{
	int go[26];
	char goc[26];
	int gol;
	int cnt;
};

node tr[2010*510];
int sz=1;

void addw(const char *s){
	int v=0;
	for(int i=0;s[i];++i){
		int p=-1;
		forn(j,tr[v].gol){
			if(tr[v].goc[j]==s[i]){
				p=tr[v].go[j];
				break;
			}
		}
		if(p==-1){
			p=tr[v].go[tr[v].gol]=sz++;
			tr[v].goc[tr[v].gol++]=s[i];
		}
		v=p;
	}
	++tr[v].cnt;
}

vector<int> *dp=new vector<int>[2010*510];

void doit(int v){
	dp[v].pb(0);
	forn(i,tr[v].cnt)
		dp[v].pb(0);
	forn(g,tr[v].gol){
		int p=tr[v].go[g];
		doit(p);
		int s=(int)dp[p].size()-1;
		dp[v].insert(dp[v].end(),s,-iinf*2-10);
		for(int k=(int)dp[v].size()-s-1;k>=0;--k){
			for(int i=1;i<=s;++i){
				int t=dp[v][k]+dp[p][i]+i*(i-1)/2;
				if(t>dp[v][k+i])
					dp[v][k+i]=t;
			}
		}
	}
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	//ios_base::sync_with_stdio(false);

	int n,k;
	cin>>n>>k;
	static char line[600];
	gets(line);
	forn(i,n){
		gets(line);
		addw(line);
	}

	doit(0);

	cout<<dp[0][k];

	return 0;
}