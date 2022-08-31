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

int val[20];
int cnt[20];
int n;
int m;
int S;
int res[4][4];
bool done;

struct action{
	enum{
		ANY,
		ROW,
		COL,
	} type;
	int a,b;
};

action acts[]={{action::ANY,0,0},{action::ANY,0,1},{action::ANY,0,2},{action::ROW,0,3},{action::ANY,1,0},{action::ANY,2,0},{action::COL,3,0},{action::ANY,1,1},{action::ANY,1,2},{action::ROW,1,3},{action::ANY,2,1},{action::COL,3,1},{action::ANY,2,2},{action::ROW,2,3},{action::COL,3,2},{action::ROW,3,3}};
const int acnt=sizeof(acts)/sizeof(acts[0]);

bool doit(int ac){
	if(ac==acnt){
		if(res[0][0]+res[1][1]+res[2][2]+res[3][3]==S && res[0][3]+res[1][2]+res[2][1]+res[3][0]==S)
			return true;
		return false;
	}
	action act=acts[ac];
	if(act.type==action::ANY){
		forn(v,m){
			if(!cnt[v])
				continue;
			--cnt[v];
			res[act.a][act.b]=val[v];
			if(doit(ac+1))
				return true;
			res[act.a][act.b]=0;
			++cnt[v];
		}
	}else if(act.type==action::ROW){
		int s=0;
		forn(i,4)
			s+=res[act.a][i];
		int v=lower_bound(val,val+m,S-s)-val;
		if(v==m||val[v]!=S-s||!cnt[v])
			return false;

		res[act.a][act.b]=S-s;
		--cnt[v];
		if(doit(ac+1))
			return true;
		res[act.a][act.b]=0;
		++cnt[v];
	}else if(act.type==action::COL){
		int s=0;
		forn(i,4)
			s+=res[i][act.b];
		int v=lower_bound(val,val+m,S-s)-val;
		if(v==m||val[v]!=S-s||!cnt[v])
			return false;

		res[act.a][act.b]=S-s;
		--cnt[v];
		if(doit(ac+1))
			return true;
		res[act.a][act.b]=0;
		++cnt[v];
	}else
		exit(321);

	return false;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	ios_base::sync_with_stdio(false);

	cin>>n;
	vector<int> src(n*n);
	forn(i,n*n){
		cin>>src[i];
		S+=src[i];
		val[i]=src[i];
	}
	S/=n;
	sort(all(src));

	if(n<=3){
		do{
			int ss1=0,ss2=0;
			bool ok=true;
			forn(i,n){
				int s1=0,s2=0;
				forn(j,n){
					s1+=src[i*n+j];
					s2+=src[j*n+i];
				}
				ss1+=src[i*n+i];
				ss2+=src[i*n+(n-1-i)];
				if(s1!=S||s2!=S){
					ok=false;
					break;
				}
			}
			if(ss1!=S||ss2!=S)
				ok=false;
			if(ok){
				forn(i,n)
					forn(j,n)
						res[i][j]=src[i*n+j];
				break;
			}
		}while(next_permutation(all(src)));
	}else{
		sort(val,val+n*n);
		m=unique(val,val+n*n)-val;
		forn(i,m)
			cnt[i]=upper_bound(all(src),val[i])-lower_bound(all(src),val[i]);

		if(!doit(0))
			exit(99);
	}

	cout<<S<<endl;
	forn(i,n){
		forn(j,n)
			cout<<res[i][j]<<' ';
		cout<<endl;
	}

	return 0;
}