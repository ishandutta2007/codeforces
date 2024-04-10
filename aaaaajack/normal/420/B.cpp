#include<cstdio>
#include<set>
#include<cstring>
#include<vector>
#define N 100100
using namespace std;
bool cand[N],first[N];
char op[N];
int num[N];
void check(set<int>& pos,set<int>& neg){
	if(pos.size()==0){
		return;
	}
	set<int>::iterator it;
	for(it=neg.begin();it!=neg.end();++it){
		cand[*it]=false;
	}
	neg.clear();
}
int main(){
	memset(cand,-1,sizeof(cand));
	memset(first,-1,sizeof(first));
	int n,m,i;
	set<int> pos,neg;
	vector<int> ans;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf(" %c%d",&op[i],&num[i]);
		if(first[num[i]]){
			first[num[i]]=false;
			if(op[i]=='-') pos.insert(num[i]);
			else neg.insert(num[i]);
		}
	}
	//printf("pos:%d\n",pos.size());
	//printf("neg:%d\n",neg.size());
	check(pos,neg);
	for(i=0;i<m;i++){
		if(op[i]=='+'){
			pos.insert(num[i]);
			if(neg.count(num[i])) neg.erase(num[i]);
		}
		else{
			neg.insert(num[i]);
			if(pos.count(num[i])) pos.erase(num[i]);
		}
		//printf("pos:%d\n",pos.size());
		//printf("neg:%d\n",neg.size());
		check(pos,neg);
	}
	for(i=1;i<=n;i++){
		if(cand[i]) ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++){
		if(i) putchar(' ');
		printf("%d",ans[i]);
	}
	if(ans.size()) putchar('\n');
	return 0;
}