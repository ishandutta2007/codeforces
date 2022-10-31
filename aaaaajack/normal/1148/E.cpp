#include<bits/stdc++.h>
#define N 300100
using namespace std;
int a[N],b[N],ai[N];
bool cmpa(int i, int j){
	return a[i]<a[j];
}
int main(){
	int n;
	bool gg=false;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		ai[i]=i;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	sort(ai,ai+n,cmpa);
	sort(a,a+n);
	sort(b,b+n);
	vector<int> vi,vj,vd;
	stack<int> s;
	for(int j=0;j<n;j++){
		while(a[j]>b[j]&&!s.empty()){
			int i=s.top();
			vi.push_back(ai[i]+1);
			vj.push_back(ai[j]+1);
			int d=min(b[i]-a[i],a[j]-b[j]);
			vd.push_back(d);
			a[i]+=d,a[j]-=d;
			if(a[i]==b[i]) s.pop();
		}
		if(a[j]>b[j]){
			gg=true;
			break;
		}
		else if(a[j]<b[j]) s.push(j);
	}
	if(gg||!s.empty()) puts("NO");
	else{
		puts("YES");
		printf("%d\n",(int)vd.size());
		for(int i=0;i<vd.size();i++){
			printf("%d %d %d\n",vi[i],vj[i],vd[i]);
		}
	}
	return 0;
}