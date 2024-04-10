#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

int n,m;
char str[100100];

const int MAX=1<<17;
struct seg{
	int tr[MAX<<1],lz[MAX<<1],fl[MAX<<1];
	void push(int cur,int sz) {
		tr[cur] = lz[cur]*sz;
		if(cur<MAX) {
			lz[cur<<1] = lz[cur<<1|1] = lz[cur];
			fl[cur<<1] = fl[cur<<1|1]=1;
		}
		lz[cur]=fl[cur]=0;
	}
	int upd(int cur,int s,int f,int l,int r,int val) {
		if(fl[cur]) push(cur,f-s+1);
		if(f<l || s>r) return tr[cur];
		else if(l<=s && f<=r) {
			fl[cur]=1;
			lz[cur]=val;
			push(cur,f-s+1);
			return tr[cur];
		}
		else {
			int nx=cur<<1,md=(s+f)>>1;
			return tr[cur] = upd(nx,s,md,l,r,val) + upd(nx+1,md+1,f,l,r,val);
		}
	}
	int sum(int cur,int s,int f,int l,int r) {
		if(fl[cur]) push(cur,f-s+1);
		if(f<l || s>r) return 0;
		else if(l<=s && f<=r) return tr[cur];
		else {
			int nx=cur<<1,md=(s+f)>>1;
			return sum(nx,s,md,l,r) + sum(nx+1,md+1,f,l,r);
		}
	}
	void pushAll(int cur,int s,int f) {
		if(fl[cur]) push(cur,f-s+1);
		if(cur<MAX) {
			int nx=cur<<1,md=(s+f)>>1;
			pushAll(nx,s,md); pushAll(nx+1,md+1,f);
		}
	}
}tr[26];

int main() {
	scanf("%d%d",&n,&m);
	scanf("%s",str);

	for(int i=0;i<n;i++) {
		tr[str[i]-'a'].upd(1,0,MAX-1,i,i,1);
	}

	int cnt[26];
	for(int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--; b--;
		for(int j=0;j<26;j++) cnt[j] = tr[j].sum(1,0,MAX-1,a,b);
		if(!c) {
			int s=a;
			for(int j=25;j>=0;j--) {
				if(!cnt[j])continue;
				//printf("(%c %d %d) ",j+'a',cnt[j],s);
				tr[j].upd(1,0,MAX-1,a,b,0);
				tr[j].upd(1,0,MAX-1,s,s+cnt[j]-1,1);
				s+=cnt[j];
			}
		} else {
			int s=a;
			for(int j=0;j<26;j++) {
				if(!cnt[j])continue;
				//printf("(%c %d %d) ",j+'a',cnt[j],s);
				tr[j].upd(1,0,MAX-1,a,b,0);
				tr[j].upd(1,0,MAX-1,s,s+cnt[j]-1,1);
				s+=cnt[j];
			}
		}
//		puts("");
	}
	for(int i=0;i<26;i++) tr[i].pushAll(1,0,MAX-1);
	
	for(int i=MAX;i<MAX+n;i++) {
		for(int j=0;j<26;j++) if(tr[j].tr[i]) {
			printf("%c",j+'a');
			break;
		}
	}

	return 0;
}