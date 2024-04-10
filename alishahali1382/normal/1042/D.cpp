#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=100000000000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 200 * 1000 + 10;

ll n, t, ans;

ll A[MAXN];
ll B[MAXN];

void merge(int l,int mid,int r){
    for (int i=l; i<mid; i++){
    	B[i]=A[i];
	}
	B[mid]=inf;
	for (int i=mid; i<r; i++){
    	B[i+1]=A[i];
	}
	B[r+1]=inf;
	int i=l, j=mid+1;
    for (int k=l; k<r; k++){
		if (B[i]<=B[j]) A[k]=B[i++];
		else A[k]=B[j++];
    }
}

void Sort(int l,int r){
	if (r-l<2) return ;
    int mid=(l+r+1)/2;
	Sort(l,mid);
	Sort(mid,r);
	for (int i=l; i<mid; i++){
		ans+=((lower_bound(A+mid, A+r, A[i]+t)-A)-mid);
	}
	merge(l, mid, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>t;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		A[i]+=A[i-1];
	}
	Sort(0, n+1);
	cout<<ans<<endl;
	
	return 0;
}