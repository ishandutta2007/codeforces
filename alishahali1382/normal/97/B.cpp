#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN=200 * 1000 + 10;

struct point{
	int x, y;
	inline operator ==(point a){
		return a.x==x && a.y==y;
	}
} A[MAXN];

bool cmp(point a, point b){
	if (a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

int n, m;

void f(int l, int r){
	if (r-l<2) return ;
	if (r-l==2){
		A[m].x=A[l+1].x;
		A[m++].y=A[l].y;
		return ;
	}
	int mid=(l+r)/2;
	for (int i=l; i<r; i++){
		if (i==mid) continue ;
		A[m].x=A[mid].x;
		A[m++].y=A[i].y;
	}
	f(l, mid);
	f(mid+1, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	m=n;
	for (int i=0; i<n; i++){
		cin>>A[i].x>>A[i].y;
	}
	sort(A, A+n, cmp);
	f(0, n);
	sort(A, A+m, cmp);
	auto ip=unique(A, A+m);
	int t=ip-A;
	cout<<t<<endl;
	for (int i=0; i<t; i++){
		cout<<A[i].x<<' '<<A[i].y<<endl;
	}
	
	
	
	return 0;
}