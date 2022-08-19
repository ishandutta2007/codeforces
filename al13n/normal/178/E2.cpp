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
#include "CImg.h"
using namespace cimg_library;
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

char ar[2100][2100];
int n;
const int A=5;
vector<PII> fig;

void dfs(int a,int b){
	fig.pb(mp(a,b));
	ar[a][b]|=16;
	const int da[]={0,0,-1,1};
	const int db[]={-1,1,0,0};
	forn(i,4){
		int aa=a+da[i];
		int bb=b+db[i];
		if((ar[aa][bb]&8)&&!(ar[aa][bb]&16))
			dfs(aa,bb);
	}
}

void save(char (*ar)[2100]){
#ifdef __ASD__

	CImg<unsigned char> img(2100,2100,1,1);
	forn(i,2100)
		forn(j,2100)
			img(i,j)=ar[i][j]==1?255:ar[i][j]==2?128:0;
	CImgDisplay disp(700,700,"nya");
	disp.display(img);
	while (!disp.is_closed()) {
      disp.wait();
	}
#endif
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	//ios_base::sync_with_stdio(false);

	cin>>n;
	forn(i,n){
		forn(j,n){
			int t;
			scanf("%d",&t);
			ar[i+5][j+5]=(char)t;
		}
	}
	forn(i,n){
		forn(j,n){
			int s=0,c=0;
			const int t=4;
			forn(a,t+t+1){
				forn(b,t+t+1){
					if(abs(a-t)+abs(b-t)<=t+1 || abs(a-t)==abs(b-t)&&abs(a-t)==3){
						if(ar[i+5+a-t][j+5+b-t]&1)
							++s;
						++c;
					}
				}
			}
			if(s*3>=c*2)
				ar[i+5][j+5]|=2;
		}
	}
	forn(i,n){
		forn(j,n){
			int s=0;
			forn(a,7){
				forn(b,7){
					if(abs(a-3)+abs(b-3)<=4 && (ar[i+5+a-3][j+5+b-3]&2)){
						s=1;
						break;
					}
				}
			}
			if(s)
				ar[i+5][j+5]|=4;
		}
	}
	forn(i,n){
		forn(j,n){
			int s=0,c=0;
			const int t=4;
			forn(a,t+t+1){
				forn(b,t+t+1){
					if(abs(a-t)+abs(b-t)<=t+1 || abs(a-t)==abs(b-t)&&abs(a-t)==3){
						if(ar[i+5+a-t][j+5+b-t]&4)
							++s;
						++c;
					}
				}
			}
			if((ar[i+5][j+5]&4) || s*3>=c*2)
				ar[i+5][j+5]|=8;
		}
	}

	int rec=0,cir=0;
	forn(i,n){
		forn(j,n){
			if((ar[i+5][j+5]&8)&&!(ar[i+5][j+5]&16)){
				fig.clear();
				dfs(i+5,j+5);
				if(fig.size()<100)
					continue;
				double a=0,b=0;
				forv(k,fig){
					a+=fig[k].X;
					b+=fig[k].Y;
				}
				a/=fig.size();
				b/=fig.size();
				double mind=1e200,maxd=-1e200;
				forv(k,fig){
					int aa=fig[k].X;
					int bb=fig[k].Y;
					if(!(ar[aa+1][bb]&8)||!(ar[aa-1][bb]&8)||!(ar[aa][bb+1]&8)||!(ar[aa][bb-1]&8)){
						double d=SQ(fig[k].X-a)+SQ(fig[k].Y-b);
						if(d<mind)
							mind=d;
						if(d>maxd)
							maxd=d;
					}
				}
				if(maxd/mind>1.4)
					++rec;
				else
					++cir;
				cerr << maxd/mind << endl;
			}
		}
	}

	cout<<cir<<' '<<rec;

	return 0;
}