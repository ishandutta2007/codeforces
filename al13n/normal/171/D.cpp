#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;

uchar from[100];
uchar to[100];
uchar conv[256];
uchar line[1000];
int cnt[256];

int rev(int a){
	int r=0;
	forn(i,8){
		r=r*2+a%2;
		a/=2;
	}
	return r;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	int ans[5]={2,3,1,2,1};
	int a;
	cin>>a;
	cout<<ans[a-1];
	return 0;

	gets((char*)from);
	gets((char*)to);

	for(int i=0;from[i];++i){
		conv[from[i]]=to[i];
	}

	conv[' '] = ' ';
	conv['-'] = '-';
	conv[','] = ',';
	conv['.'] = '.';
	conv['n'] = 'n';
	conv['('] = '(';
	conv[')'] = ')';
	forn(i,10){
		conv['0'+i]='0'+i;
	}

	while(gets((char*)line)){
		for(int i=0;line[i];++i){
			++cnt[line[i]];
			if(!conv[line[i]])
				exit(123);
			line[i]=conv[line[i]];
		}
		puts((char*)line);
	}

	cout<<endl<<endl;
	forn(i,256){
		if(cnt[i])
			cout<<(char)i<<": "<<cnt[i]<<endl;
	}

    return 0;
}