#include<bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define mp      make_pair
#define orz     1000000007
using namespace std;
int n,m,k[100005],p[100005],cnt,outf[250005],outt[250005],outk[250005],ans,l,r;
set<int> s[100005],S;
vector<int> v;
bool cmp(int x,int y){return k[x]>k[y];}
void del(){
	for(set<int>::iterator it=s[p[r]].begin();it!=s[p[r]].end();++it)if(S.count(*it))S.erase(*it),v.pb(*it);
}
void rec(){
	for(int i=0;i<v.size();++i)S.insert(v[i]);
	v.clear();
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",k+i);
		cnt+=k[i],p[i]=i;
		for(int j=1;j<=k[i];++j){
			scanf("%d",&x);
			s[i].insert(x);
		}
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;++i)k[i]-=cnt/n;
	for(int i=1;i<=cnt%n;++i)--k[p[i]];
	l=1,r=n;
	S=s[p[1]];
	del();
	while(l<r){
		if(!k[p[l]]){
			++l;
			if(l==r) break;
			v.clear(),S=s[p[l]];
			del();
			continue;
		}
		if(!k[p[r]]){
			rec();
			--r;
			if(l==r) break;
			del();
			continue;
		}
		int x=*S.begin();
		S.erase(x),s[p[r]].insert(x),--k[p[l]],++k[p[r]];
		++ans,outf[ans]=p[l],outt[ans]=p[r],outk[ans]=x;
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)printf("%d %d %d\n",outf[i],outt[i],outk[i]);
	return 0;
}