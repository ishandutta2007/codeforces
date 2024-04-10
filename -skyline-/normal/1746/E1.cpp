#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
mt19937 rnd(time(0));
int n;
char c[10];
void prt(vector<int> &v){
	for(int i=0;i<v.size();++i)printf(" %d",v[i]);
}
int main(){
	scanf("%d",&n);
	if(n==1){
		printf("! 1\n");
		fflush(stdout);
		return 0;
	}
	vector<int> vt,vf;
	for(int i=1;i<=n;++i){
		if(i&1)vt.pb(i);
		else vf.pb(i);
	}
	printf("? %d",vt.size());
	prt(vt);
	printf("\n");
	fflush(stdout);
	scanf("%s",c);
	if(c[0]=='N')swap(vt,vf);
	while(vt.size()+vf.size()>2){
		vector<int> v1,v2,v3,v4;
		for(int i=0;i<vt.size();++i){
			if(i&1)v1.pb(vt[i]);
			else v2.pb(vt[i]);
		}
		for(int i=0;i<vf.size();++i){
			if(i&1)v4.pb(vf[i]);
			else v3.pb(vf[i]);
		}
		int x=vt.size(),y=vf.size();
		if(x>=2&&x%2==0&&y%2==1){
			v1.clear();
			v2.clear();
			for(int i=0;i<vt.size();++i){
				if((i&1)&&i>1)v1.pb(vt[i]);
				else v2.pb(vt[i]);
			}
		}
		printf("? %d",v1.size()+v3.size());
		prt(v1);
		prt(v3);
		printf("\n");
		fflush(stdout);
		scanf("%s",c);
		if(c[0]=='Y'){
			vt=v1;
			for(int i=0;i<v3.size();++i)vt.pb(v3[i]);
			vf=v2;
		}
		else{
			vt=v2;
			for(int i=0;i<v4.size();++i)vt.pb(v4[i]);
			vf=v1;
		}
	}
	vector<int> v;
	for(int i=0;i<vt.size();++i)v.pb(vt[i]);
	for(int i=0;i<vf.size();++i)v.pb(vf[i]);
	printf("! %d\n",v[0]);
	fflush(stdout);
	scanf("%s",c);
	if(c[1]=='('){
		printf("! %d\n",v[1]);
		fflush(stdout);
	}
    return 0;
}