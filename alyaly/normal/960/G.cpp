#include<bits/stdc++.h>
//#define int long long
#define P 998244353
#define N 300000
#define Ri register int
//#define ygycl
using namespace std;
int n,m,K,logn[N+1],jc[N+1],njc[N+1],A,B;
#ifdef ygycl
int rev[21][N+1],yg[21][N+1][2];
#else
int rev[N+1];
#endif
int p0[N+1],p1[N+1],p2[N+1],p3[N+1],p4[N+1],p5[N+1];
inline int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=(nans*10+c-'0')%P,c=getchar();return nans;}
inline int ksm(int x,int y){int nans=1;for(;y;y>>=1,x=1ll*x*x%P)if(y&1)nans=1ll*nans*x%P;return nans;}
inline int qny(int x){return ksm(x,P-2);}
inline int ksm(int x,int y,int p){int nans=1;for(;y;y>>=1,x=1ll*x*x%p)if(y&1)nans=1ll*nans*x%p;return nans;}
inline int qny(int x,int p){return ksm(x,p-2,p);}
inline int zgw(int x){return (1<<(logn[x-1]+1));}
inline void mp(int&x){x-=((x>=P)?P:0);}
inline void swp(int&x,int&y){x^=(y^=(x^=y));}
inline int C(int x,int y){if(y>x||y<0)return 0;return jc[x]*njc[y]%P*njc[x-y]%P;}
void ycl(){
	jc[0]=njc[0]=1;for(int i=1;i<=N;i++)jc[i]=1ll*jc[i-1]*i%P;
	njc[N]=qny(jc[N]);for(int i=N-1;i>=1;i--)njc[i]=1ll*njc[i+1]*(i+1)%P;
	for(Ri i=2;i<=N;++i)logn[i]=logn[i/2]+1;
#ifdef ygycl
	for(Ri i=2;i<=(1<<19);i<<=1){
		Ri ni=ksm(3,(P-1)/i);
		for(Ri j=0;j<(1<<19);j+=i){
			for(Ri nt=1,k=j;k<j+i/2;++k,nt=1ll*nt*ni%P){
				yg[logn[i]][k][0]=nt;
			}
		}
		ni=qny(ni);
		for(Ri j=0;j<(1<<19);j+=i){
			for(Ri nt=1,k=j;k<j+i/2;++k,nt=1ll*nt*ni%P){
				yg[logn[i]][k][1]=nt;
			}
		}
	}
	for(int i=0,ni=1;i<=19;i++,ni<<=1){
		for(Ri j=0;j<ni;++j){rev[i][j]=rev[i][j>>1]>>1;if(j&1)rev[i][j]|=(ni>>1);}
	}
#endif
}
#ifdef ygycl
inline void dft(int*x,int len,int nfl){
	int fln=1-((nfl+1)>>1);
	for(Ri i=0;i<len;++i)if(i<rev[logn[len]][i])swp(x[i],x[rev[logn[len]][i]]);
	for(Ri i=2;i<=len;i<<=1){
		for(Ri j=0;j<len;j+=i){
			for(Ri k=j;k<j+i/2;++k){
				Ri np=x[k],nq=1ll*yg[logn[i]][k][fln]*x[k+i/2]%P;
				x[k]=np+nq,mp(x[k]);
				x[k+i/2]=np-nq+P,mp(x[k+i/2]);
			}
		}
	}
	if(nfl==-1)for(Ri ni=qny(len),i=0;i<len;++i)x[i]=1ll*x[i]*ni%P;
}
#else
inline void dft(int*x,int len,int nfl){
	for(Ri i=0;i<len;i++){
		rev[i]=rev[i>>1]>>1;
		if(i&1)rev[i]|=(len>>1);
	}
	for(Ri i=0;i<len;i++)if(i<rev[i])swap(x[i],x[rev[i]]);
	for(Ri i=2;i<=len;i<<=1){
		Ri ni=ksm(3,(P-1)/i);if(nfl==-1)ni=qny(ni);
		for(Ri j=0;j<len;j+=i){
			Ri nt=1;
			for(Ri k=j;k<j+i/2;++k){
				Ri np=x[k],nq=x[k+i/2];
				x[k]=(np+1ll*nt*nq)%P;
				x[k+i/2]=np-1ll*nt*nq%P+P;
				mp(x[k+i/2]);
				nt=1ll*nt*ni%P;
			}
		}
	}
	if(nfl==-1)for(Ri ni=qny(len),i=0;i<len;++i)x[i]=1ll*x[i]*ni%P;
}
#endif
int np[N+1],nans[N+1],nq[N+1];
inline void qd(int*x,int len){for(int i=0;i<len-1;i++)x[i]=1ll*x[i+1]*(i+1)%P;x[len-1]=0;}
inline void jf(int*x,int len){for(int i=len-1;i>0;i--)x[i]=1ll*x[i-1]*qny(i)%P;x[0]=0;}
inline void qnp(int*x,int len){
	memset(np,0,(len*sizeof(int)*2));
	memset(nans,0,(len*sizeof(int)*2));
	nans[0]=qny(x[0]);
	for(Ri i=2;i<=len;i<<=1){
		for(Ri j=0;j<i;j++)np[j]=x[j];
		dft(np,i<<1,1),dft(nans,i<<1,1);
		for(Ri j=0;j<(i<<1);j++)nans[j]=1ll*nans[j]*(2ll-1ll*np[j]*nans[j]%P+P)%P;
		dft(nans,i<<1,-1);
		memset(nans+i,0,i*sizeof(int));
	}
	memcpy(x,nans,len*sizeof(int)*2);
}
int nnp[N+1],ep[N+1],eans[N+1];
void ln(int*x,int len){
	memcpy(nnp,x,len*sizeof(int));
	for(int i=len;i<2*len;i++)nnp[i]=0;
	qnp(nnp,len);
	qd(x,len);
	dft(x,2*len,1),dft(nnp,2*len,1);
	for(int i=0;i<2*len;i++)x[i]=1ll*x[i]*nnp[i]%P;
	dft(x,2*len,-1);for(int i=len;i<2*len;i++)x[i]=0;
	jf(x,len);
	return;
}
void exp(int*x,int len){
	memset(eans,0,sizeof(eans));
	memset(ep,0,sizeof(ep));
	eans[0]=1;
	for(int ii=2;ii<=len;ii<<=1){
		memcpy(ep,eans,ii*sizeof(int));ln(ep,ii);
		for(int i=0;i<ii;i++)ep[i]=(x[i]-ep[i]+P)%P;
		ep[0]=(ep[0]+1)%P;
		dft(eans,2*ii,1),dft(ep,2*ii,1);
		for(int i=0;i<2*ii;i++)eans[i]=1ll*eans[i]*ep[i]%P;
		dft(eans,2*ii,-1);
		for(int i=ii;i<2*ii;i++)eans[i]=0;
	}
	memcpy(x,eans,len*sizeof(int));
}
void ksm(int*x,int len,int y){
	ln(x,len);
	for(int i=0;i<len;i++)x[i]=1ll*x[i]*y%P;
	exp(x,len);
}
void ksm1(int*x,int len,int y){
	int xp=0,xq;
	while(!x[xp]&&xp<len)xp++;
	if(xp==len)return;
	xq=qny(x[xp]);
	for(int i=0;i<len-xp;i++)x[i]=1ll*x[i+xp]*xq%P;
	ksm(x,len,y);xq=ksm(qny(xq),y);
	for(int i=len-1;i>=y*xp;i--)x[i]=1ll*x[i-y*xp]*xq%P;
	for(int i=min(len,y*xp)-1;i>=0;i--)x[i]=0;
}
inline void R(int*x,int len){
	for(Ri i=0;i<len/2;++i)swp(x[i],x[len-i-1]);
}
inline void mo(int*x,int xlen,int*y,int ylen){
	memset(y+ylen,0,(xlen-ylen)<<2);
	while(ylen&&!y[ylen-1])--ylen;
	for(Ri i=0;i<ylen;++i)nq[i]=y[ylen-1-i];
	qnp(nq,xlen);
	memcpy(np,x,xlen<<3);
	R(np,xlen);
	memset(np+xlen-ylen+1,0,(ylen-1)<<2);
	memset(nq+xlen-ylen+1,0,(ylen-1)<<2);
	dft(np,2*xlen,1),dft(nq,2*xlen,1);
	for(Ri i=0;i<2*xlen;++i)np[i]=1ll*np[i]*nq[i]%P;
	dft(np,2*xlen,-1);
	memset(np+xlen-ylen+1,0,(ylen-1)<<2);
	R(np,xlen-ylen+1);
	dft(np,xlen,1),dft(y,xlen,1);
	for(Ri i=0;i<xlen;++i)np[i]=1ll*np[i]*y[i]%P;
	dft(np,xlen,-1);
	for(Ri i=0;i<xlen;++i)x[i]=x[i]-np[i]+P,mp(x[i]);
	return;
}
//namespace adv{
//	int seg[21][N+1],f[21][N+1],sm[21][N+1],dm[N+1];
//	void fz(int d,int nl,int nr){
//		int l=2*nl,r=2*nr+1;
//		int mid=(l+r)/2,nmid=(nl+nr)/2;
//		if(nl!=nr){
//			fz(d+1,nl,nmid);
//			fz(d+1,nmid+1,nr);
//			for(Ri i=l;i<=mid;++i)p2[i-l]=seg[d+1][i];for(Ri i=mid+1;i<=r;++i)p2[i-l]=0;dft(p2,r-l+1,1);
//			for(Ri i=mid+1;i<=r;++i)p3[i-mid-1]=seg[d+1][i];for(Ri i=mid+1;i<=r;++i)p3[i-l]=0;dft(p3,r-l+1,1);
//			for(Ri i=0;i<=r-l;++i)p2[i]=1ll*p2[i]*p3[i]%P;
//			dft(p2,r-l+1,-1);
//			for(Ri i=l;i<=r;++i)seg[d][i]=p2[i-l];
//		}else{
//			seg[d][l]=P-p1[nl];
//			seg[d][l+1]=1;
//		}
//	}
//	void fsm(int d,int nl,int nr){
//		int l=2*nl,r=2*nr+1;
//		int mid=(l+r)/2,nmid=(nl+nr)/2;
//		if(nl!=nr){
//			fsm(d+1,nl,nmid);
//			fsm(d+1,nmid+1,nr);
//			for(Ri i=l;i<=mid;++i)p2[i-l]=sm[d+1][i];for(Ri i=mid+1;i<=r;++i)p2[i-l]=0;dft(p2,r-l+1,1);
//			for(Ri i=mid+1;i<=r;++i)p3[i-mid-1]=sm[d+1][i];for(Ri i=mid+1;i<=r;++i)p3[i-l]=0;dft(p3,r-l+1,1);
//			for(Ri i=0;i<=r-l;++i)p2[i]=1ll*p2[i]*p3[i]%P;
//			dft(p2,r-l+1,-1);
//			for(Ri i=l;i<=r;++i)sm[d][i]=p2[i-l];
//		}else{
//			if(nl<n){
//				sm[d][l]=P-p1[nl];
//				sm[d][l+1]=1;
//			}else sm[d][l]=1,sm[d][l+1]=0;
//		}
//	}
//	void cal(int d,int nl,int nr){
//		if(nr-nl<=70){
//			for(Ri i=nl;i<=nr;++i)for(Ri j=(p0[i]=0),nt=1;j<=2*(nr-nl)+1;j++,nt=1ll*nt*p1[i]%P)p0[i]=p0[i]+1ll*f[d][j]*nt%P,mp(p0[i]);
//			return;
//		}
//		Ri l=2*nl,r=2*nr+1;
//		Ri mid=(l+r)/2,nmid=(nl+nr)/2;
//		if(nl!=nr){
//			memcpy(f[d+1],f[d],(r-l+1)<<1);
//			for(Ri i=l;i<=l+(mid-l+2)/2;++i)p2[i-l]=seg[d+1][i];
//			mo(f[d+1],(r-l+1)/2,p2,(mid-l+1)/2+1);
//			cal(d+1,nl,nmid);
//			memcpy(f[d+1],f[d],(r-l+1)<<1);
//			for(Ri i=mid+1;i<=mid+1+(r-mid+1)/2;++i)p2[i-mid-1]=seg[d+1][i];
//			mo(f[d+1],(r-l+1)/2,p2,(r-mid)/2+1);
//			cal(d+1,nmid+1,nr);
//		}else{
//			p0[nl]=f[d][0];
//			mp(p0[nl]);
//		}
//	}
//	void lag(int d,int nl,int nr){
//		int l=2*nl,r=2*nr+1;
//		int mid=(l+r)/2,nmid=(nl+nr)/2;
//		if(nl!=nr){
//			lag(d+1,nl,nmid);
//			lag(d+1,nmid+1,nr);
//			for(Ri i=mid+1;i<=r;++i)p2[i-mid-1]=sm[d+1][i];for(Ri i=mid+1;i<=r;++i)p2[i-l]=0;
//			dft(p2,r-l+1,1);
//			for(Ri i=l;i<=mid;++i)p3[i-l]=f[d+1][i];for(Ri i=mid+1;i<=r;++i)p3[i-l]=0;
//			dft(p3,r-l+1,1);
//			for(Ri i=0;i<=r-l;++i)p2[i]=1ll*p2[i]*p3[i]%P;
//			dft(p2,r-l+1,-1);
//			for(Ri i=l;i<=r;++i)f[d][i]+=p2[i-l];
//			for(Ri i=mid+1;i<=r;++i)p2[i-mid-1]=f[d+1][i];for(Ri i=mid+1;i<=r;++i)p2[i-l]=0;
//			dft(p2,r-l+1,1);
//			for(Ri i=l;i<=mid;++i)p3[i-l]=sm[d+1][i];for(Ri i=mid+1;i<=r;++i)p3[i-l]=0;
//			dft(p3,r-l+1,1);
//			for(Ri i=0;i<=r-l;++i)p2[i]=1ll*p2[i]*p3[i]%P;
//			dft(p2,r-l+1,-1);
//			for(Ri i=l;i<=r;++i)f[d][i]+=p2[i-l],mp(f[d][i]);
//		}else{
//			f[d][l]=p0[nl];
//		}
//	}
//}
signed main(){
	ycl();
	n=qread(),A=qread()-1,B=qread()-1;int tn=zgw(n+1);
	if(A<0||B<0){
		cout<<0<<endl;return 0;
	}
	for(int i=0;i<tn;i++)p0[i]=p1[i]=1ll*jc[i-1]*njc[i]%P;
	ksm1(p0,tn,A);
	ksm1(p1,tn,B);
	for(int i=0;i<tn;i++)p0[i]=1ll*p0[i]*njc[A]%P,p1[i]=1ll*p1[i]*njc[B]%P;
	dft(p0,2*tn,1),dft(p1,2*tn,1);
	for(int i=0;i<2*tn;i++)p0[i]=1ll*p0[i]*p1[i]%P;
	dft(p0,2*tn,-1);
	printf("%lld\n",1ll*p0[n-1]*jc[n-1]%P);
	return 0;
}
/*
100000 20000 30000

9 18948465
237846 895734 37248 89547 238947 859437 238947 857439 3849
*/