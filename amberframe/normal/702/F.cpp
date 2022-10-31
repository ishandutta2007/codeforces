#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>
using namespace std;

typedef pair<int,int> mp;
#define pb push_back
const int maxn = 200005;
const int thres = 450;

struct Reg {
	int l,r,inc,ans;
	bool operator<(const Reg &v) const {
		return l<v.l;
	}
};
vector <mp> tsh;
vector <Reg> reg,tmp;

struct Cus {
	int resi,ans,id;
	bool operator<(const Cus &v) const {
		return resi<v.resi; 
	}
} cus[maxn];

int n,ans[maxn],k;
void rebuild() {
	for (int i=0;i<reg.size();i++) {
		int inc=reg[i].inc,ans=reg[i].ans;
		for (int j=reg[i].l;j<=reg[i].r;j++)
			cus[j].resi-=inc,cus[j].ans+=ans;
	}
	reg.clear(); reg.pb((Reg){1,k,0,0});
	sort(cus+1,cus+k+1);
}
int binary(int pri,const Reg &r) {
	int lb=r.l,rb=r.r;
	while (rb-lb>1) {
		int mid=lb+rb>>1;
		if (cus[mid].resi>=pri+r.inc)
			rb=mid;else lb=mid;
	}
	return rb;
}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("tshirts.in","r",stdin);
		freopen("tshirts.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int c,q,i=1;i<=n;i++)
		scanf("%d %d",&c,&q),tsh.pb(mp(-q,c));
	sort(tsh.begin(),tsh.end());
	scanf("%d",&k);
	for (int i=1;i<=k;i++)
		scanf("%d",&cus[i].resi),cus[i].id=i;
	rebuild();
	
	for (int i=0;i<n;i++) {
		int pri=tsh[i].second;tmp.clear();
		for (int j=0;j<reg.size();j++) {
			if (cus[reg[j].l].resi>=pri+reg[j].inc)
				tmp.pb((Reg){reg[j].l,reg[j].r,reg[j].inc+pri,reg[j].ans+1});
			else if (cus[reg[j].r].resi<pri+reg[j].inc)
				tmp.pb((Reg){reg[j].l,reg[j].r,reg[j].inc,reg[j].ans});
			else {
				int pos=binary(pri,reg[j]);
				tmp.pb((Reg){reg[j].l,pos-1,reg[j].inc,reg[j].ans});
				tmp.pb((Reg){pos,reg[j].r,reg[j].inc+pri,reg[j].ans+1});
			}
		}
		swap(tmp,reg);
		if (reg.size()>=thres) rebuild();
	}
	rebuild();
	for (int i=1;i<=k;i++)
		ans[cus[i].id]=cus[i].ans;
	for (int i=1;i<=k;i++)
		printf("%d ",ans[i]);
	return 0;
}