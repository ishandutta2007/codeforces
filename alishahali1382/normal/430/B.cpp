#include <bits/stdc++.h>

using namespace std;

const int MAXN=110;


int n, k, x, ans, top, cur, tmp;
int A[MAXN];

int st[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>k>>x;
	for (int i=0; i<n; i++) cin>>A[i];
	
	for (int i=0; i<=n; i++){
		top=0;
		cur=-1;
		for (int j=0; j<i; j++){
			st[top++]=A[j];
		}
		st[top++]=x;
		for (int j=i; j<n; j++){
			if (top<3 || A[j]==st[top-1] || !(st[top-1]==st[top-2] && st[top-2]==st[top-3])){
				st[top++]=A[j];
				continue ;
			}
			tmp=st[top-1];
			while (top && st[top-1]==tmp){
				top--;
				cur++;
				//cerr<<i<<' '<<top<<" debug1"<<endl;
			}
			st[top++]=A[j];
		}
		if (top>=3 && st[top-1]==st[top-2] && st[top-2]==st[top-3]){
			tmp=st[top-1];
			while (top && st[top-1]==tmp){
				top--;
				cur++;
				//cerr<<i<<' '<<top<<endl;
			}
		}
		ans=max(cur, ans);
	}
	cout<<ans<<endl;
	
	return 0;
}