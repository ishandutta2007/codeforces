#include<bits/stdc++.h>
char c[111][11];
int n,r[111],b[111];
int dpr[1<<16|15][300],dpb[1<<16|15][300];
int pc[1<<16|15],sr[1<<16|15],sb[1<<16|15],er[1<<16|15],eb[1<<16|15];
int main()
{
	//fprintf(stderr,"%d\n",sizeof dpr >>20);
	scanf("%d",&n);
	memset(dpr,0x3f,sizeof dpr);
	memset(dpb,0x3f,sizeof dpb);
	dpr[0][0+150]=dpb[0][0+150]=0;
	register int i,ii,iii;
	for(i=0;i<n;i++)
		scanf("%s%d%d",c[i],r+i,b+i),sr[1<<i]=r[i],sb[1<<i]=b[i],
		er[1<<i]=(c[i][0]=='R'),eb[1<<i]=(c[i][0]=='B');
	for(i=0;i<(1<<n);i++)pc[i]=pc[i>>1]+(i&1);
	for(i=1;i<(1<<n);i++)
	{
		if(pc[i]==1)continue;
		int t=i&-i;
		sr[i]=sr[i^t]+sr[t];
		sb[i]=sb[i^t]+sb[t];
		er[i]=er[i^t]+er[t];
		eb[i]=eb[i^t]+eb[t];
	}
	for(i=1;i<(1<<n);i++)
		for(ii=0;ii<n;ii++)if((i>>ii)&1)
		{
			int T=(i^(1<<ii));
			for(iii=-140;iii<140;iii++)if(dpr[T][iii+150]<1e9||dpb[T][iii+150]<1e9)
			{
				// R remain 
				
				int RC=iii+dpr[T][iii+150]-sr[T],BC=0,TL=dpr[T][iii+150];
				
				//printf("%d %d %d %d %d %d\n",i,ii,iii,RC,BC,TL);
				
				if(TL<1e9)
				{
					if(RC<r[ii]-er[T])BC+=r[ii]-er[T]-RC,TL+=r[ii]-er[T]-RC,RC=r[ii]-er[T];
					if(BC<b[ii]-eb[T])RC+=b[ii]-eb[T]-BC,TL+=b[ii]-eb[T]-BC,BC=b[ii]-eb[T];
					if(r[ii]>=er[T])RC-=r[ii]-er[T];
					if(b[ii]>=eb[T])BC-=b[ii]-eb[T];
					//printf("%d %d %d %d %d\n",RC,BC,TL,sr[i],sb[i]);
					if(RC){if(dpr[i][sr[i]+RC-TL+150]>TL)dpr[i][sr[i]+RC-TL+150]=TL;}
					else{if(dpb[i][sb[i]+BC-TL+150]>TL)dpb[i][sb[i]+BC-TL+150]=TL;}
				} 
				// B remain 
				
				BC=iii+dpb[T][iii+150]-sb[T],RC=0,TL=dpb[T][iii+150];
				if(TL<1e9)
				{
					if(RC<r[ii]-er[T])BC+=r[ii]-er[T]-RC,TL+=r[ii]-er[T]-RC,RC=r[ii]-er[T];
					if(BC<b[ii]-eb[T])RC+=b[ii]-eb[T]-BC,TL+=b[ii]-eb[T]-BC,BC=b[ii]-eb[T];
					if(r[ii]>=er[T])RC-=r[ii]-er[T];
					if(b[ii]>=eb[T])BC-=b[ii]-eb[T];
					//printf("%d %d %d <%d|%d> =%d\n",i,ii,iii,RC,BC,TL);
					if(RC){if(dpr[i][sr[i]+RC-TL+150]>TL)dpr[i][sr[i]+RC-TL+150]=TL;}
					else{if(dpb[i][sb[i]+BC-TL+150]>TL)dpb[i][sb[i]+BC-TL+150]=TL;}
				}
			}
		}
	int ans=1e9;
	for(iii=-140;iii<140;iii++)
		ans=std::min(ans,std::min(dpr[(1<<n)-1][iii+150],dpb[(1<<n)-1][iii+150]));
	printf("%d\n",ans+n);
}