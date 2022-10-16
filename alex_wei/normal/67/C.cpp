#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef unsigned long long ull;

#define fi first
#define se second
#define pb emplace_back
#define mem(x,v,n) memset(x,v,sizeof(x[0])*n)
#define cpy(x,y,n) memcpy(x,y,sizeof(x[0])*n)

const int N=5e3+5;


int f[N][N],pres[N],pret[N];
int ti,td,tr,te;
string s,t;
int main(){
	cin>>ti>>td>>tr>>te>>s>>t; memset(f,0x3f,sizeof(f));
	for(int i=0;i<=s.size();i++,mem(pret,0,N)){
		if(i>1)pres[s[i-2]]=i-1;
		for(int j=0;j<=t.size();j++){
			if(i==0){f[i][j]=j*ti; continue;}
			if(j==0){f[i][j]=i*td; continue;}
			f[i][j]=min(f[i-1][j]+td,f[i][j-1]+ti);
			if(s[i-1]==t[j-1])f[i][j]=min(f[i][j],f[i-1][j-1]);
			else f[i][j]=min(f[i][j],f[i-1][j-1]+tr);
			int x=pres[t[j-1]],y=pret[s[i-1]];
			if(x&&y)f[i][j]=min(f[i][j],f[x-1][y-1]+td*(i-x-1)+ti*(j-y-1)+te);
			pret[t[j-1]]=j;
		}
	}
	cout<<f[s.size()][t.size()]<<endl;
	return 0;
}