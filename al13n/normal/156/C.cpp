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

const int mod=iinf+7;
int dp[110][110*30];
char str[110];

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);

	dp[0][0]=1;
	forn(n,100){
		forn(s,n*25+1){
			forn(k,26){
				dp[n+1][s+k]=(dp[n+1][s+k]+dp[n][s])%mod;
			}
		}
	}
	
	int tc;
	cin>>tc;
	gets(str);
	forn(qqq,tc){
		gets(str);
		int n=strlen(str);
		int s=0;
		forn(i,n){
			s+=str[i]-'a';
		}
		cout<<(dp[n][s]+mod-1)%mod<<'\n';
	}

	return 0;
}