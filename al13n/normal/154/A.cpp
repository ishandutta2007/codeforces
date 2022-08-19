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

char src[110000];
int n;
bool not[27][27];
int dp[110000][27];

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	gets(src);
	n=strlen(src);
	int k;
	cin>>k;
	forn(i,k){
		string s;
		cin>>s;
		not[s[0]-'a'][s[1]-'a']=not[s[1]-'a'][s[0]-'a']=true;
	}
	forn(i,n+1){
		forn(j,27){
			dp[i][j]=iinf;
		}
	}
	dp[0][26]=0;
	forn(i,n){
		forn(j,27){
			if(!not[j][src[i]-'a'])
				dp[i+1][src[i]-'a']=min(dp[i+1][src[i]-'a'],dp[i][j]);
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
		}
	}
	int res=iinf;
	forn(i,27){
		res=min(res,dp[n][i]);
	}
	cout<<res;

    return 0;
}