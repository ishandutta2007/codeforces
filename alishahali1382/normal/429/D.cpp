#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=500 * 1000 + 10;

struct point{
	ll x, y, ind;
} A[MAXN], B[MAXN], C[MAXN];

bool cmp(point a, point b){
	if (a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

ll n, out=1000000000000LL;
ll ans1, ans2;
ld ans=1e10, tmp;

ld hyp(point a, point b){
	ld x=a.x-b.x, y=a.y-b.y;
	return sqrt(x*x+y*y);
}

void merg(int l, int mid, int r){
	for (int i=l; i<r; i++) C[i]=B[i];
	int i=l, j=mid, k=l;
	for (; i<mid && j<r;){
		if (C[i].y<C[j].y) B[k++]=C[i++];
		else B[k++]=C[j++];
	}
	while (i<mid) B[k++]=C[i++];
	while (j<r) B[k++]=C[j++];
}

ld f(int l, int r){
	if (r-l<2) return 1e10;
	int mid=(l+r)/2;
	ld z=min(f(l, mid), f(mid, r));
	merg(l, mid, r);
	int top=0;
	for (int i=l; i<r; i++){
		if (abs(B[i].x-A[mid].x)<z) C[top++]=B[i];
	}
	for (int i=0; i<top; i++){
		for (int j=i+1; j<top && (C[j].y-C[i].y<z); j++){
			tmp=hyp(C[i], C[j]);
			if (tmp<z){
				z=tmp;
				if (z<ans){
					ans=z;
					ans1=C[i].ind;
					ans2=C[j].ind;
					ll xx=C[i].x-C[j].x, yy=C[i].y-C[j].y;
					out=xx*xx+yy*yy;
				}
			}
		}
	}
	return z;
}

ll arr[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//scanf("%d", &n);
	cin>>n;
	ll xx=0;
	for (int i=0; i<n; i++){
		//scanf("%d %d", &A[i].x, &A[i].y);
		cin>>arr[i];
		xx+=arr[i];
		A[i].x=i+1;
		A[i].y=xx;
		A[i].ind=i;
	}
	sort(A, A+n, cmp);
	for (int i=0; i<n; i++) B[i]=*new point (A[i]);
	f(0, n);
	if (ans2<ans1) swap(ans1, ans2);
	cout<<out<<endl;
	//printf("%d %d %lf\n", ans1, ans2, ans);
	
	return 0;
}