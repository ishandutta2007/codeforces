#include<bits/stdc++.h>
using namespace std;
int T,n,m,k[100003],st[100003],idx[100003],BG[100003],ed;
long long sum[100003],b[200003],sm[3][100003],a[100003];
bool cmpa(int x,int y){return x>y;}
bool cmpidx(int x,int y){return sum[x]*k[y]>sum[y]*k[x];}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			scanf("%lld",a+i);
		int TTT=0;
		for(int i=0;i<m;i++){
			scanf("%d",k+i);sum[i]=0;
			for(int j=0;j<k[i];j++){
				scanf("%lld",b+TTT);
				sum[i]+=b[TTT++];
			}
			st[i+1]=st[i]+k[i];
			idx[i]=i;
		}
		sort(a,a+n,cmpa);
		sort(idx,idx+m,cmpidx);
		for(int i=0;i<m;i++)
			BG[idx[i]]=i;
		for(int i=0;i<m;i++)//tpatp/2,btp%2 
			sm[0][i+1]=sm[0][i]+(a[i]*k[idx[i]]>=sum[idx[i]]);
		for(int i=0;i<m;i++)
			sm[1][i+1]=sm[1][i]+(a[i]*k[idx[i+1]]>=sum[idx[i+1]]);
		for(int i=0;i<m;i++)
			sm[2][i+1]=sm[2][i]+(a[i+1]*k[idx[i]]>=sum[idx[i]]);
		for(int i=0;i<m;i++)
			for(int j=0;j<k[i];j++){
				long long nwsum=sum[i]-b[j+st[i]],nwk=k[i]-1;
				int l=0,r=m,mid;
				while(l!=r){
					mid=(l+r>>1);
					if(sum[idx[mid]]*nwk<=nwsum*k[idx[mid]])
						r=mid;
					else
						l=mid+1;
				}// 
				ed=l;
				if(sum[i]*nwk>nwsum*k[i])ed--;
				int nw=bool(nwsum<=nwk*a[ed]),bg=BG[i];
				if(ed==bg)
					nw+=(sm[0][bg]+sm[0][m]-sm[0][bg+1]);
				if(ed<bg)
					nw+=(sm[0][ed]+sm[0][m]-sm[0][bg+1])+sm[2][bg]-sm[2][ed];
				if(ed>bg)
					nw+=(sm[0][bg]+sm[0][m]-sm[0][ed+1])+sm[1][ed]-sm[1][bg];
				if(nw==m)
					putchar('1');
				else
					putchar('0');
			}
		putchar('\n');
	}
}