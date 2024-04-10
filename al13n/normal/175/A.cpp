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
typedef unsigned short ushort;



int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);

	string s;
	cin>>s;
	int n=s.length();
	int r=-1;
	for(int a=1;a<n;++a){
		for(int b=a+1;b<n;++b){
			if(a>8||b-a>8||n-b>8)
				continue;
			string s1=s.substr(0,a);
			string s2=s.substr(a,b-a);
			string s3=s.substr(b);
			if(s1.length()>1&&s1[0]=='0'||s2.length()>1&&s2[0]=='0'||s3.length()>1&&s3[0]=='0')
				continue;
			int v1=atoi(s1.c_str());
			int v2=atoi(s2.c_str());
			int v3=atoi(s3.c_str());
			if(v1>1000000||v2>1000000||v3>1000000)
				continue;
			r=max(r,v1+v2+v3);
		}
	}
	cout<<r;

	return 0;
}