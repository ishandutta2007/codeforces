#include<bits/stdc++.h>
#define ll long long
#define N 200015
using namespace std;
int n,m,a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int MAX = 1e8+7;
	int ex = 1e4;
	cin>>n>>m;
	int cur = 0;
	for(int i = 1;i <= n;++i){
		if(cur+(i-1)/2<=m){
			cur += (i-1)/2;
			a[i] = i; 
		}else{
			if(cur >= m) a[i] = MAX,MAX+=ex;
			else{
				a[i] = 2*(i-1)-2*(m-cur);
				cur = m;
			}
		}
	}
	if(cur != m) cout << -1 << endl;
	else{
		for(int i = 1;i <= n;++i) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}