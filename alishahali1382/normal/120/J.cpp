#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=500 * 1000 + 10;

struct point{
	ll x, y, ind, zar;
} A[MAXN];

int B[MAXN], C[MAXN];

bool cmp(point a, point b){
	if (a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

bool cmp2(int a, int b){
	if (A[a].y==A[b].y) return A[a].x<A[b].x;
	return A[a].y<A[b].y;
}

ll n;
ll ans1, ans2, ans11, ans22;
ld ans=1e10, tmp;

ld hyp(point a, point b){
	ld x=a.x-b.x, y=a.y-b.y;
	return sqrt(x*x+y*y);
}

void merg(int l, int mid, int r){
	for (int i=l; i<r; i++) C[i]=B[i];
	int i=l, j=mid, k=l;
	for (; i<mid && j<r;){
		if (A[C[i]].y<A[C[j]].y) B[k++]=C[i++];
		else B[k++]=C[j++];
	}
	while (i<mid) B[k++]=C[i++];
	while (j<r) B[k++]=C[j++];
}

ld f(int l, int r){
	if (r-l<2) return 1e10;
	/*
	if (r-l<7){
		ld z=1e10;
		for (int i=l; i<r; i++){
			for (int j=i+1; j<r; j++){
				z=min(z, hyp(A[i], A[j]));
				if (z<ans){
					ans=z;
					ans1=C[i].ind;
					ans11=C[i].zar;
					ans2=C[j].ind;
					ans22=C[j].zar;
				}
			}
		}
		return z;
	}*/
	int mid=(l+r)/2;
	ld z=min(f(l, mid), f(mid, r));
	merg(l, mid, r);
	//sort(B+l, B+r, cmp2);
	int top=0;
	for (int i=l; i<r; i++){
		if (abs(A[B[i]].x-A[mid].x)<z) C[top++]=B[i];
	}
	for (int i=0; i<top; i++){
		for (int j=i+1; j<top && (A[C[j]].y-A[C[i]].y<z); j++){
			tmp=hyp(A[C[i]], A[C[j]]);
			if (tmp<z){
				z=tmp;
				if (z<ans){
					ans=z;
					ans1=A[C[i]].ind;
					ans11=A[C[i]].zar;
					ans2=A[C[j]].ind;
					ans22=A[C[j]].zar;/*
					if (ans11%2 != ans22%2){
						if (ans22%2) ans22--;
						else ans22++;
					}
					if (ans11/2 != ans22/2){
						if (ans22/2) ans22-=2;
						else ans22+=2;
					}*/
					
				}
			}
		}
	}
	return z;
}



int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//scanf("%d", &n);
	cin>>n;
	for (int i=0; i<n; i++){
		//scanf("%d %d", &A[i].x, &A[i].y);
		cin>>A[i].x>>A[i].y;
		A[i].zar=0;
		if (A[i].x<0){
			A[i].zar++;
			A[i].x*=-1;
		}
		if (A[i].y<0){
			A[i].zar+=2;
			A[i].y*=-1;
		}
		A[i].ind=i+1;
		B[i]=i;
	}
	sort(A, A+n, cmp);
	f(0, n);
	cout<<ans1<<' '<<ans11+1<<' '<<ans2<<' '<<4-ans22<<endl;
	//printf("%d %d %lf\n", ans1, ans2, ans);
	
	return 0;
}