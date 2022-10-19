#include<bits/stdc++.h>
#define ll long long
#define N 200015
using namespace std;
int n;
ll c[N];
map<ll,ll> m;
struct node{
	int id;
	ll val;
	bool operator<(const node &x) const{
		return val < x.val;
	}
}a[N]; 
void print(int id){
	cout << a[id].id << endl;
	exit(0);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;++i) cin>>a[i].val,a[i].id = i;
	sort(a+1,a+n+1); 
	for(int i = 1;i < n;++i) c[i] = a[i+1].val-a[i].val,m[c[i]]++;
	if(n==2){
		cout << 1 << endl;
		return 0;
	}
	m[c[1]]--;
	if(m[c[n-1]]==n-2) print(1);
	m[c[1]]++;
	m[c[n-1]]--;
	if(m[c[1]]==n-2) print(n);
	m[c[n-1]]++;
	for(int i = 2;i <= n-1;++i){
		m[c[i-1]]--;m[c[i]]--;m[c[i-1]+c[i]]++;
		if(m[c[i-1]+c[i]]==n-2) print(i);
		m[c[i-1]]++;m[c[i]]++;m[c[i-1]+c[i]]--;
	}
	cout << -1 << endl;
	return 0;
}