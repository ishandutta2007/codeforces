#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;

pii a[3];
char res[301][301];

bool check1(int *ord,int inv=0) {
	int x=a[ord[0]].fi + a[ord[1]].fi + a[ord[2]].fi;

	if(a[ord[0]].se!=a[ord[1]].se || a[ord[0]].se!=a[ord[2]].se || x!=a[ord[0]].se) 
		return false;

	int n=x;
	for(int i=0;i<n;i++) {
		for(int j=0,s=0;j<3;s+=a[ord[j++]].fi) {
			for(int k=0;k<a[ord[j]].fi;k++){
				res[i][s+k] = ord[j]+'A';
			}
		}
	}

	if(inv) {
		for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
			swap(res[i][j],res[j][i]);
	}
	printf("%d\n",n);
	for(int i=0;i<n;i++)
		printf("%s\n",res[i]);
	return true;
}
bool check2(int *ord,int inv=0) {
	int x=a[ord[0]].fi + a[ord[1]].fi;
	if(x != a[ord[2]].fi || a[ord[0]].se != a[ord[1]].se || a[ord[0]].se + a[ord[2]].se != x)
		return false;

	int n=x;
	for(int i=0;i<a[ord[0]].se;i++) {
		for(int j=0,s=0;j<2;s+=a[ord[j++]].fi) {
			for(int k=0;k<a[ord[j]].fi;k++)
				res[i][s+k] = ord[j]+'A';
		}
	}
	for(int i=a[ord[0]].se;i<n;i++) {
		for(int j=0;j<n;j++)
			res[i][j] = ord[2]+'A';
	}

	if(inv) {
		for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
			swap(res[i][j],res[j][i]);
	}

	printf("%d\n",n);
	for(int i=0;i<n;i++)
		printf("%s\n",res[i]);
	return true;
}
bool check3(int *ord) {
	for(int i=0;i<3;i++)
		swap(a[i].fi,a[i].se);

	bool val = check2(ord,1);
	for(int i=0;i<3;i++) 
		swap(a[i].fi,a[i].se);
	return val;
}
bool check4(int *ord) {
	for(int i=0;i<3;i++)
		swap(a[i].fi,a[i].se);


	bool val=check1(ord,1);
	for(int i=0;i<3;i++)
		swap(a[i].fi,a[i].se);
	return val;
}
int main() {
	int ord[3]={0,1,2};
	for(int i=0;i<3;i++)
		scanf("%d%d",&a[i].first,&a[i].second);

	do{
		for(int s=0;s<1<<3;s++) {
			for(int i=0;i<3;i++) if(s>>i&1) 
				swap(a[ord[i]].first,a[ord[i]].second);

			if(check1(ord) || check2(ord) || check3(ord) || check4(ord)) 
				return 0;

			for(int i=0;i<3;i++) if(s>>i&1) 
				swap(a[ord[i]].first,a[ord[i]].second);
		}

	}while(next_permutation(ord,ord+3));
	puts("-1");

	return 0;
}