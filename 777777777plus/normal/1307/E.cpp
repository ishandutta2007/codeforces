#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3+5;
const int mod = 1e9+7;

int n,m,ans1,ans2;
int s[N],cntl[N][N],cntr[N][N];
struct cow{
	int f,h;
	cow(int _f=0,int _h=0){
		f=_f;h=_h;
	}
	friend bool operator < (cow a,cow b){
		return a.f<b.f||(a.f==b.f&&a.h<b.h);
	}
}a[N];
 
int main(){
	//freopen("data1.in", "r", stdin);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=1;i<=m;++i)cin>>a[i].f>>a[i].h;
	++n;s[n]=n;
	++m;a[m].f=n;a[m].h=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)cntl[i][j]=cntl[i-1][j];
		cntl[i][s[i]]++;
	}
	for(int i=n;i>=1;--i){
		for(int j=1;j<=n;++j)cntr[i][j]=cntr[i+1][j];
		cntr[i][s[i]]++;
	}
	sort(a+1,a+m+1);
	for(int i=0;i<n;++i){
		int tot=0,anstmp=1,ssp=s[i+1];
		bool flag=0;
		for(int l=1,r=1;l<=m;l=++r){
			while(a[r+1].f==a[l].f)r++;
			int s1=a[l].f;
			if(l==r){
				if(cntl[i][s1]>=a[l].h||cntr[i+1][s1]>=a[l].h){
					if(s1==ssp){
						if(cntr[i+1][s1]==a[l].h)flag=1;
					}
					else{
						if(cntl[i][s1]>=a[l].h&&cntr[i+1][s1]>=a[l].h)
						anstmp=1ll*anstmp*2%mod;
					}
					tot++;
				}
			}
			else{
				if((cntl[i][s1]>=a[l].h&&cntr[i+1][s1]>=a[l+1].h)
				 ||(cntl[i][s1]>=a[l+1].h&&cntr[i+1][s1]>=a[l].h)){
				 	if(s1==ssp){
					 	for(int j=l;j<=r;++j)
						if(a[j].h==cntr[i+1][s1]){
					 		flag=1;
					 		int c=0;
					 		for(int k=l;k<=r;++k)
					 		if(k!=j&&a[k].h<=cntl[i][s1]){
					 			c++;
					 		}
					 		anstmp=1ll*anstmp*c%mod;
					 	}
				 	}
				 	else{
				 		int cnt=0;
					 	for(int j=l;j<=r;++j)
						if(a[j].h<=cntr[i+1][s1]){
					 		int c=upper_bound(a+l,a+r+1,cow(s1,cntl[i][s1]))-a-1;
					 		if(c<j)cnt+=c-l+1;
					 		else cnt+=c-l;
					 	}
					 	anstmp=1ll*anstmp*cnt%mod;
				 	}
				 	tot+=2;
				 }
				else if(max(cntl[i][s1],cntr[i+1][s1])>=a[l].h){
					if(s1==ssp){
					 	for(int j=l;j<=r;++j)
						if(a[j].h==cntr[i+1][s1]){
							flag=1;
						}
					}
					else{
						int c=0;
					 	for(int j=l;j<=r;++j){
							if(cntl[i][s1]>=a[j].h){
						 		c++;
						 	}
							if(cntr[i+1][s1]>=a[j].h){
						 		c++;
						 	}
					 	}
						anstmp=1ll*anstmp*c%mod;
					}
					tot++;
				}
			}
		}
		if(flag){
			//cout<<i<<" "<<tot<<" "<<anstmp<<endl;
			if(tot>ans1)ans1=tot,ans2=anstmp;
			else if(tot==ans1)ans2=(ans2+anstmp)%mod;
		}
	}
	cout<<ans1-1<<" "<<ans2<<endl;
}