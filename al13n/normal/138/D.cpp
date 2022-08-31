#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-8
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second

char ar[21][21];
int n,m;
int dp[21][21][21][21];//yxhw
int tmp[500];
int curtmp;
bool tmpinuse;

int doit(int y,int x,int h,int w){
	int &res=dp[y][x][h][w];
	if(res!=-1)
		return res;
	if(!w||!h)
		return 0;
	forn(i,h){
		forn(j,w){
			if(ar[y+i][x+j]=='R'){//vertical
				doit(y,x,h,j);
				doit(y,x+j+1,h,w-j-1);
			}else if(ar[y+i][x+j]=='L'){
				doit(y,x,i,w);
				doit(y+i+1,x,h-i-1,w);
			}else if(ar[y+i][x+j]=='X'){
				doit(y,x,i,j);
				doit(y+i+1,x,h-i-1,j);
				doit(y,x+j+1,i,w-j-1);
				doit(y+i+1,x+j+1,h-i-1,w-j-1);
			}else if(ar[y+i][x+j]!='N')
				exit(3241);
		}
	}
	++curtmp;
	if(tmpinuse)
		exit(3241);
	tmpinuse=true;
	forn(i,h){
		forn(j,w){
			if(ar[y+i][x+j]=='R'){//vertical
				tmp[doit(y,x,h,j)^doit(y,x+j+1,h,w-j-1)]=curtmp;
			}else if(ar[y+i][x+j]=='L'){
				tmp[doit(y,x,i,w)^doit(y+i+1,x,h-i-1,w)]=curtmp;
			}else if(ar[y+i][x+j]=='X'){
				tmp[doit(y,x,i,j)^doit(y+i+1,x,h-i-1,j)^doit(y,x+j+1,i,w-j-1)^doit(y+i+1,x+j+1,h-i-1,w-j-1)]=curtmp;
			}else if(ar[y+i][x+j]!='N')
				exit(3241);
		}
	}
	res=0;
	while(tmp[res]==curtmp)
		++res;
	tmpinuse=false;
	return res;
}

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	ios_base::sync_with_stdio(false);

	int N,M;
	cin>>N>>M;
	if(N==1&&M==1){
		cout<<"WIN";
		exit(0);
	}
	string src[30];
	forn(i,N){
		cin>>src[i];
	}

	int res=0;
	forn(qq,2){
		n=m=(N+M-2)/2+1;
		memset(ar,'N',sizeof(ar));
		memset(dp,-1,sizeof(dp));
		forn(i,N){
			forn(j,M){
				if((i+j)%2!=qq)
					continue;
				ar[(i+j-qq)/2][(i-j+M-1)/2]=src[i][j];
			}
		}
		res^=doit(0,0,n,m);
	}

	if(res)
		cout<<"WIN";
	else
		cout<<"LOSE";

	return 0;
}