//11:37
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+5;
const ll INF = 2e18;

void add(ll &x,ll y){
	x+=y;if(x>=INF)x=INF;
}

int n,m;
ll k;
char s[N];
int lcp[N][N];
struct inv{
	int l,r;
	inv(int _l=0,int _r=0){
		l=_l;r=_r;
	}
	friend bool operator < (inv a,inv b){
		int g=lcp[a.l][b.l];
		int lena=a.r-a.l+1,lenb=b.r-b.l+1;
		if(lena>g&&lenb>g)return s[a.l+g]<=s[b.l+g];
		return lena<=lenb;
	}
}sub[N*N];

ll getcnt(int L,int R){
	static int nex[N];
	for(int i=1;i<=n;++i){
		int l=i,r=n;
		while(l!=r){
			int mid=l+r>>1;
			if(inv(L,R)<inv(i,mid))r=mid;
			else l=mid+1;
		}
		if(inv(L,R)<inv(i,l))nex[i]=l;
		else nex[i]=-1;
	}
	if(nex[1]==-1)return 0;
	static ll f[N][N];
	memset(f,0,sizeof(f));
	f[nex[1]][1]=1;
	for(int i=nex[1];i<n;++i)
	for(int j=1;j<=m;++j)
	if(f[i][j]){
		add(f[i+1][j],f[i][j]);
		if(~nex[i+1])add(f[nex[i+1]][j+1],f[i][j]); 
	}
	return f[n][m];
}

int main(){
	scanf("%d%d%lld",&n,&m,&k);
	scanf("%s",s+1);
	for(int i=n;i>=1;--i)
	for(int j=n;j>=1;--j){
		if(s[i]==s[j])lcp[i][j]=lcp[i+1][j+1]+1;
		else lcp[i][j]=0;
	}
	int tot=0;
	for(int i=1;i<=n;++i)
	for(int j=i;j<=n;++j)
	sub[++tot]=inv(i,j);
	sort(sub+1,sub+tot+1);
	int l=1,r=tot;
	while(l!=r){
		int mid=l+r+1>>1;
		if(getcnt(sub[mid].l,sub[mid].r)>=k)l=mid;
		else r=mid-1;
	}
	for(int i=sub[l].l;i<=sub[l].r;++i)putchar(s[i]);
	printf("\n");
}