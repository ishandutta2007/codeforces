#include<bits/stdc++.h>
int n,q,a[1<<13],x[1<<22],y[1<<22];
int cid;
int merge(int u,int v){return x[++cid]=u,y[cid]=v,cid;}
struct block
{
	int pos[1<<9],sz;
	int idx[1<<9][1<<9];
	void recurbuild(int L,int R)
	{
		if(L==R){idx[L][L]=pos[L];return;}
		int M=(L+R)>>1;
		recurbuild(L,M),recurbuild(M+1,R);
		register int i,ii,iii;
		int cur[1<<9][1<<9];
		for(i=L;i<=R;i++)
			for(ii=L;ii<=R;ii++)
				if(pos[i]<pos[ii])
				{
					int DL=-1,DR=-1,TL=-1,TR=-1;
					for(iii=L;iii<=M;iii++)
						if(pos[iii]<=pos[ii]&&pos[iii]>=pos[i])
						{
							if(DL<0)DL=DR=iii;
							if(pos[DL]>pos[iii])DL=iii;
							else if(pos[DR]<pos[iii])DR=iii;
						}
					for(iii=M+1;iii<=R;iii++)
						if(pos[iii]<=pos[ii]&&pos[iii]>=pos[i])
						{
							if(TL<0)TL=TR=iii;
							if(pos[TL]>pos[iii])TL=iii;
							else if(pos[TR]<pos[iii])TR=iii;
						}
					if(~DL&&~TL)cur[i][ii]=merge(idx[DL][DR],idx[TL][TR]);
					else cur[i][ii]=0;
				}
		for(i=L;i<=R;i++)
			for(ii=L;ii<=R;ii++)
				if(pos[i]<pos[ii])if(cur[i][ii])idx[i][ii]=cur[i][ii];
	}
	void build()
	{
		for(sz=0;sz<255;sz++)if(!pos[sz+1])break;
		recurbuild(0,sz);
	}
}B[18];
int p[1<<13],w[1<<17];
int rebuild(int l,int r)
{
	register int i;
	int pl[19],pr[19];
	for(i=0;i<=18;i++)pl[i]=pr[i]=-1;
	for(i=l;i<=r;i++)
	{
		int idb=a[i]>>8,idt=a[i]&255;
		if(~pl[idb])
		{
			if(B[idb].pos[pl[idb]]>i)pl[idb]=idt;
			else if(B[idb].pos[pr[idb]]<i)pr[idb]=idt;
		}else pl[idb]=pr[idb]=idt;
	}
	int ret=0;
	for(i=0;i<=18;i++)
		if(~pl[i])
		{
			if(!ret)ret=B[i].idx[pl[i]][pr[i]];
			else ret=merge(ret,B[i].idx[pl[i]][pr[i]]);
		}
	return ret;
}
int main()
{
	scanf("%d%d",&n,&q),cid=n;
	register int i;
	for(i=1;i<=n;i++)scanf("%d",a+i),a[i]--;
	for(i=1;i<=n;i++)p[a[i]]=i,B[a[i]>>8].pos[a[i]&255]=i;
	for(i=0;i<=((n-1)>>8);i++)B[i].build();
	for(i=1;i<=q;i++){int l,r;scanf("%d%d",&l,&r),w[i]=rebuild(l,r);}
	printf("%d\n",cid);
	for(i=n+1;i<=cid;i++)printf("%d %d\n",x[i],y[i]);
	for(i=1;i<=q;i++)printf("%d ",w[i]);puts("");
}
/*
Please don't let me down.
*/