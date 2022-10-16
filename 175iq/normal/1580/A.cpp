#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define SZ(v) ((int)v.size())
#define fs first
#define sc second
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
int t,n,m;
char s[410][410];
int sum[410][410];
int getsum(int num,int i,int j,int ii,int jj){
	int sum1=sum[ii][jj]-sum[i-1][jj]-sum[ii][j-1]+sum[i-1][j-1];
	if(num)	return sum1;
	else return (ii-i+1)*(jj-j+1)-sum1;
}
int f,ans;
int get(int i,int j,int ii,int jj){
	f=0;
	if(getsum(0,i+1,j,ii-1,j)+getsum(0,i,j+1,i,jj-1)+getsum(1,i+1,j+1,ii-1,jj-1)>=ans)	f=1;
	return getsum(0,i+1,j,ii-1,j)+getsum(0,i,j+1,i,jj-1)+getsum(1,i+1,j+1,ii-1,jj-1)+getsum(0,ii,j+1,ii,jj-1)+getsum(0,i+1,jj,ii-1,jj);
}
int main(){
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&m);
		rep(i,1,n){
			scanf("%s",&s[i][1]);
		}
		rep(i,1,n){
			rep(j,1,m){
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='1');
			}
		}
		ans=16;
		rep(i,1,n){
			rep(j,1,m){
				rep(ii,i+4,n){
					int brk=-1;
					rep(jj,j+3,m){
						ans=min(ans,get(i,j,ii,jj));
						if(f){
							brk=jj;
							break;
						}
					}
					if(brk==j+3){
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}