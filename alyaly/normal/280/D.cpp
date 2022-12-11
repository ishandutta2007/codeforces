#include<bits/stdc++.h>
#define N 100000
//#define int long long
#define gc() getchar()
#define mid (l+r)/2
using namespace std;
int n,K,a[N+1],ans,pb;
int Q,q0[N+1],q1[N+1],q2[N+1],q3[N+1];
pair<int,int>b[51];
struct nod{
	int s0,s1,pre0,pre1,suf0,suf1,s;
	int pl0,pr0,pl1,pr1,pp0,pp1,ps0,ps1;
	bool laz;
}seg[4*N+1],O;
int qread(){int nans=0,nf=1;char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();if(c=='-')nf=-1,c=gc();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=gc();return nans*nf;}
void putin(){
	n=qread();
	for(int i=1;i<=n;i++)a[i]=qread();
	Q=qread();
	for(int i=1;i<=Q;i++){
		q0[i]=qread();
		if(!q0[i])q1[i]=qread(),q2[i]=qread();
		else q1[i]=qread(),q2[i]=qread(),q3[i]=qread();
	}
}
void segdown(int u,int l,int r){
	if(!seg[u].laz)return;
	swap(seg[u].s0,seg[u].s1),swap(seg[u].pre0,seg[u].pre1),swap(seg[u].suf0,seg[u].suf1),seg[u].s=-seg[u].s;
	swap(seg[u].pl0,seg[u].pl1),swap(seg[u].pr0,seg[u].pr1),swap(seg[u].pp0,seg[u].pp1),swap(seg[u].ps0,seg[u].ps1);
	if(l!=r)seg[u*2].laz^=1,seg[u*2+1].laz^=1;
	seg[u].laz=0;
}
nod mge(nod p,nod q){
	nod nans;
	if(p.s0==0&&p.s1==0)return q;
	else if(q.s0==0&&q.s1==0)return p;
	if(p.suf0+q.pre0>=max(p.s0,q.s0))nans.s0=p.suf0+q.pre0,nans.pl0=p.ps0,nans.pr0=q.pp0;
	else if(p.s0>=q.s0)nans.s0=p.s0,nans.pl0=p.pl0,nans.pr0=p.pr0;
	else nans.s0=q.s0,nans.pl0=q.pl0,nans.pr0=q.pr0;
	if(p.suf0+q.s>=q.suf0)nans.suf0=p.suf0+q.s,nans.ps0=p.ps0;
	else nans.suf0=q.suf0,nans.ps0=q.ps0;
	if(q.pre0+p.s>=p.pre0)nans.pre0=q.pre0+p.s,nans.pp0=q.pp0;
	else nans.pre0=p.pre0,nans.pp0=p.pp0;
	if(p.suf1+q.pre1>=max(p.s1,q.s1))nans.s1=p.suf1+q.pre1,nans.pl1=p.ps1,nans.pr1=q.pp1;
	else if(p.s1>=q.s1)nans.s1=p.s1,nans.pl1=p.pl1,nans.pr1=p.pr1;
	else nans.s1=q.s1,nans.pl1=q.pl1,nans.pr1=q.pr1;
	if(p.suf1-q.s>=q.suf1)nans.suf1=p.suf1-q.s,nans.ps1=p.ps1;
	else nans.suf1=q.suf1,nans.ps1=q.ps1;
	if(q.pre1-p.s>=p.pre1)nans.pre1=q.pre1-p.s,nans.pp1=q.pp1;
	else nans.pre1=p.pre1,nans.pp1=p.pp1;
	nans.s=p.s+q.s;nans.laz=0;return nans;
}
void segup(int u,int l,int r){
	segdown(u,l,r);
	if(l!=r){
		segdown(u*2,l,mid),segdown(u*2+1,mid+1,r);
		seg[u]=mge(seg[u*2],seg[u*2+1]);
	}
}
void segbuild(int u,int l,int r){
	if(l==r){
		seg[u].s=a[l];
		if(a[l]>0){
			seg[u].s0=seg[u].pre0=seg[u].suf0=a[l];
			seg[u].pl0=seg[u].pr0=seg[u].pp0=seg[u].ps0=l;
			seg[u].pl1=seg[u].ps1=r+1,seg[u].pr1=seg[u].pp1=l-1;
		}else{
			seg[u].s1=seg[u].pre1=seg[u].suf1=-a[l];
			seg[u].pl1=seg[u].pr1=seg[u].pp1=seg[u].ps1=l;
			seg[u].pl0=seg[u].ps0=r+1,seg[u].pr0=seg[u].pp0=l-1;
		}
	}else segbuild(u*2,l,mid),segbuild(u*2+1,mid+1,r),segup(u,l,r);
}
void segqf(int u,int l,int r,int nl,int nr){
	if(l>nr||r<nl||l>r)return;
	else if(l>=nl&&r<=nr)seg[u].laz^=1;
	else segdown(u,l,r),segqf(u*2,l,mid,nl,nr),segqf(u*2+1,mid+1,r,nl,nr),segup(u,l,r);
}
void segadd(int u,int l,int r,int np,int nx){
	if(l==r){
		segdown(u,l,r);
		seg[u].s=nx;
		if(nx>0){
			seg[u].s0=seg[u].pre0=seg[u].suf0=nx,seg[u].s1=seg[u].pre1=seg[u].suf1=0;
			seg[u].pl0=seg[u].pr0=seg[u].pp0=seg[u].ps0=l;
			seg[u].pl1=seg[u].ps1=r+1,seg[u].pr1=seg[u].pp1=l-1;
		}else{
			seg[u].s1=seg[u].pre1=seg[u].suf1=-nx,seg[u].s0=seg[u].pre0=seg[u].suf0=0;
			seg[u].pl1=seg[u].pr1=seg[u].pp1=seg[u].ps1=l;
			seg[u].pl0=seg[u].ps0=r+1,seg[u].pr0=seg[u].pp0=l-1;
		}
	}else{
		segdown(u,l,r);
		if(np<=mid)segadd(u*2,l,mid,np,nx);
		else segadd(u*2+1,mid+1,r,np,nx);
		segup(u,l,r);
	}
}
nod segreq(int u,int l,int r,int nl,int nr){
	if(l>nr||r<nl)return O;
	else if(l>=nl&&r<=nr)return segup(u,l,r),seg[u];
	else{
		segup(u,l,r);
		nod np=segreq(u*2,l,mid,nl,nr),nq=segreq(u*2+1,mid+1,r,nl,nr);
		return mge(np,nq);
	}
}
void ycl(){
	segbuild(1,1,n);
}
void cal0(){
	for(int i=1;i<=Q;i++){
		if(!q0[i]){
			segadd(1,1,n,q1[i],q2[i]);
		}else{
			int nans=0;nod nd;
			for(int j=1;j<=q3[i];j++){
				nd=segreq(1,1,n,q1[i],q2[i]);
				nans+=nd.s0;
				b[j]=make_pair(nd.pl0,nd.pr0);
				segqf(1,1,n,nd.pl0,nd.pr0);
			}
			cout<<nans<<'\n';
			for(int j=1;j<=q3[i];j++){
				segqf(1,1,n,b[j].first,b[j].second);
			}
		}
	}
}
signed main(){
	putin();
	ycl();
	cal0();
	return 0;
}
/*
15
-4 8 -3 -10 10 5 -7 -7 0 -3 3 8 -10 7 -9
2
0 11 -10
1 6 12 1

20
-5 -1 -9 -6 4 -5 6 1 5 -3 6 -3 10 1 4 -10 -10 -9 10 -6
1
1 1 14 3
*/