#include <bits/stdc++.h>

using namespace std;

const int MAXN=1010;


int n, m, ans1, ans2, tmp;
int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>A[i];
	}
	sort(A, A+m);
	tmp=n;
	for (int i=0; i<m; i++){
		if (tmp>A[i]){
			ans2+=A[i]*(A[i]+1)/2;
			tmp-=A[i];
			continue ;
		}
		ans2+=A[i]*(A[i]+1)/2-(A[i]-tmp)*(A[i]-tmp+1)/2;
		break ;
	}
	int* x;
	
	for (; n>0; n--){
		x=max_element(A, A+m);
		ans1+=*x;
		--*x;
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}