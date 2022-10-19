#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n;
char s[500005];
__uint128_t mm[500005],bs[500005],mo=1000000007;
int m2[500005],sb[500005],om=111339248186143ull;
__uint128_t m3[500005],bb[500005],oo=13131;
int LCP(int u,int v){
	int l=1,r=min(n-u+1,n-v+1);
	while(l<=r){
		int mid=(l+r)>>1;
		if(mm[u+mid-1]-mm[u-1]*bs[mid]==mm[v+mid-1]-mm[v-1]*bs[mid])
			l=mid+1;
		else r=mid-1;
	}
	return r;
}
int LCS(int u,int v){
	int l=1,r=min(u,v);
	while(l<=r){
		int mid=(l+r)>>1;
		if(mm[u]-mm[u-mid]*bs[mid]==mm[v]-mm[v-mid]*bs[mid])
			l=mid+1;
		else r=mid-1;
	}
	return r;
}
int S[26][500005],hh[500005],qq[500005];
int wz[114514];
int qz[500005],hz[500005];
int QZ[21][500005];
int zx(int l,int r){
	int lg=31-__builtin_clz(r-l+1);
	return min(QZ[lg][l],QZ[lg][r-(1<<lg)+1]);
}
vector<int>yz[200005];
int sa[2000005],rk[2000005],ork[2000005];
int id[2000005],cnt[2000005];
int fa1[200005],fa2[200005];
int findfather1(int x){
	return x==fa1[x]?x:fa1[x]=findfather1(fa1[x]);
}
int findfather2(int x){
	return x==fa2[x]?x:fa2[x]=findfather2(fa2[x]);
}
int main(){
	cin>>n;
	scanf("%s",s+1);
	mm[0]=0,bs[0]=1;
	m2[0]=0,sb[0]=1;
	m3[0]=0,bb[0]=1;
	for(int i=1;i<=n;++i){
		mm[i]=mm[i-1]*mo+s[i];
		bs[i]=bs[i-1]*mo;
		m2[i]=(1ll*m2[i-1]*om+s[i])%mod;
		sb[i]=1ll*sb[i-1]*om%mod;
		m3[i]=m3[i-1]*oo+s[i];
		bb[i]=bb[i-1]*oo;
	}
	int m;
	cin>>m;
	int M=300;
	for(int i=1;i<=n;++i){
		rk[i]=s[i];
		++cnt[rk[i]];
	}
	for(int i=1;i<=M;++i)cnt[i]+=cnt[i-1];
	for(int i=n;i>=1;--i)
		sa[cnt[rk[i]]--]=i;
	for(int cd=1;cd<=n;cd<<=1){
		for(int i=1;i<=M;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)id[i]=sa[i];
		for(int i=1;i<=n;++i)++cnt[rk[id[i]+cd]];
		for(int i=1;i<=M;++i)cnt[i]+=cnt[i-1];
		for(int i=n;i>=1;--i)
			sa[cnt[rk[id[i]+cd]]--]=id[i];
		for(int i=1;i<=M;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)id[i]=sa[i];
		for(int i=1;i<=n;++i)++cnt[rk[id[i]]];
		for(int i=1;i<=M;++i)cnt[i]+=cnt[i-1];
		for(int i=n;i>=1;--i)
			sa[cnt[rk[id[i]]]--]=id[i];
		for(int i=1;i<=n;++i)ork[i]=rk[i];
		int p=0;
		for(int i=1;i<=n;++i){
			if(ork[sa[i]]==ork[sa[i-1]]&&ork[sa[i]+cd]==ork[sa[i-1]+cd]){
				rk[sa[i]]=p;
			}else rk[sa[i]]=++p;
		}
		if(p==n)break;
		M=p;
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j)S[j][i]=S[j][i-1];
		++S[s[i]-'a'][i];
	}
	for(int i='a';i<='z';++i)wz[i]=0;
	for(int i=1;i<=n;++i){
		qq[i]=wz[s[i]];
		wz[s[i]]=i;
	}
	for(int i='a';i<='z';++i)wz[i]=n+1;
	for(int i=n;i>=1;--i){
		hh[i]=wz[s[i]];
		wz[s[i]]=i;
	}
	for(int i=1;i<=n;++i)qz[i]=n+1;
	for(int i=1;i<=n;++i)hz[i]=n+1;
	for(int i=1;i<=n+1;++i)fa1[i]=fa2[i]=i;
	for(int cd=1;cd<=n;++cd){
		int A=cd,B=cd+cd;
		while(B<=n){
			int lcp=LCP(A,B),lcs=LCS(A,B);
			lcp=min(lcp,cd),lcs=min(lcs,cd);
			--lcs;
			if(s[A]==s[B]&&lcp+lcs>=cd){
				int l1=A-lcs,r1=A+lcp-cd;
				int l2=l1+cd+cd-1,r2=r1+cd+cd-1;
				for(int i=findfather1(l1);i<=r1;i=fa1[i]){
					qz[i]=min(qz[i],cd);
					fa1[i]=findfather1(i+1);
				}
				for(int i=findfather2(l2);i<=r2;i=fa2[i]){
					hz[i]=min(hz[i],cd);
					fa2[i]=findfather2(i+1);
				}
			}
			A+=cd,B+=cd;
		}
	}
	for(int i=1;i<=n;++i)qz[i]=min(n+1,i+qz[i]+qz[i]-1);
	for(int i=1;i<=n;++i)hz[i]=max(0,i-hz[i]-hz[i]+1);
	for(int i=1;i<=n;++i){
		QZ[0][i]=qz[i];
	}
	for(int i=1;i<=20;++i)for(int j=1;j<=n;++j)if(j+(1<<(i-1))<=n)
		QZ[i][j]=min(QZ[i-1][j],QZ[i-1][j+(1<<(i-1))]);
	for(int i=1;i<=n;++i)for(int j=i;j<=n;j+=i)
		yz[j].emplace_back(i);
	int sq=sqrt(n+0.5);
	for(int te=1;te<=m;++te){
		int l,r;
		scanf("%d%d",&l,&r);
		int mn=-1;
		for(int i=0;i<26;++i)if(S[i][r]-S[i][l-1]>1){
			mn=4;
			break;
		}
		if(mn==-1){
			puts("-1");
			continue;
		}
		int zz=r-l+1;
		for(auto i:yz[zz]){
			if(i==zz)continue;
			if(mm[r-i]-mm[l-1]*bs[r-i-l+1]==mm[r]-mm[l+i-1]*bs[r-l-i+1]){
				int A1=(m2[r-i]-1ll*m2[l-1]*sb[r-i-l+1])%mod;
				int A2=(m2[r]-1ll*m2[l+i-1]*sb[r-l-i+1])%mod;			
				if((A1-A2)%mod==0){
					if(m3[r-i]-m3[l-1]*bb[r-i-l+1]==m3[r]-m3[l+i-1]*bb[r-l-i+1]){
						mn=1;
						break;
					}
				}
			}
		}
		if(mn>1){
			for(int i=1;i<=sq;++i){
				if(l+i-1>r-i+1)break;
				if(mm[l+i-1]-mm[l-1]*bs[i]==mm[r]-mm[r-i]*bs[i]){
					mn=2;
					break;
				}
			}
		}
		if(mn>2){
			for(int j=max(1,rk[l]-sq-1);j<=min(n,rk[l]+sq+1);++j){
				int i=r-sa[j]+1;
				if(i<=0||l+i-1>r-i+1)continue;
				if(mm[l+i-1]-mm[l-1]*bs[i]==mm[r]-mm[r-i]*bs[i]){
					mn=2;
					break;
				}
			}
		}
		if(mn>2){
			if(qz[l]<=r||hz[r]>=l)mn=2;
		}
		if(mn>2){
			if(hh[l]<=r||qq[r]>=l)mn=3;
		}
		if(mn>3){
			if(zx(l,r)<=r)mn=3;
		}
		printf("%d\n",mn);
	}
	return 0;
}