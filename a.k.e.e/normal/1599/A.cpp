#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n, a[200005], u[200005], x[200005], y[200005];
int l1, r1, zff[200005];
char s[200005];
int xsum, ysum;

bool cmp(int x, int y) {
	return x < y;
}

void zf(int x) {
	if (x == 1);// printf("+");
		else printf("-");
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	sort(a + 1, a + n + 1, cmp);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) u[i]=s[i]=='R';
	
	for (int i = 1; i <= n; i++) {
		
		if (u[i] & 1) {//xy
			x[i]=1;
		}
		else x[i]=-1;
		
		if (i > 1) {//
			if (x[i] == x[i - 1]) l1++;
		}
	}
	r1 = l1 + 1;
	
	zff[n] = x[n];//
	for (int i = n - 1; i >= 1; i--) {
		zff[i] = zff[i + 1] * -1;
	}
	
	printf("%d %c\n", a[r1],zff[r1]>0?'R':'L');
	r1++;
	for (int i = 2; i <= n; i++) {
		if (zff[r1 - 1] * x[i] < 0) {//
			printf("%d %c\n", a[r1],zff[r1]>0?'R':'L');
			r1++;
		}
		else {//
			printf("%d %c\n", a[l1],zff[l1]>0?'R':'L');
			l1--;
		}
	}
	
	return 0;
}