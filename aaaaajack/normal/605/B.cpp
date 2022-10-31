#include<cstdio>
#include<set>
#include<utility>
#include<algorithm>
#include<vector>
#define N 100100
#define F first
#define S second
using namespace std;
pair<pair<int,int>,int> p[N];
vector<int> last;
int pe[N];
int ef[N],et[N];
int main(){
	int n,m,now=2;
	bool wrong=false;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) pe[i]=i-1;
	for(int i=0;i<m;i++){
		scanf("%d%d",&p[i].F.F,&p[i].F.S);
		p[i].S=i;
		p[i].F.S*=-1;
	}
	sort(p,p+m);
	for(int i=0;i<m;i++){
		if(p[i].F.S){
			if(now>n){
				wrong=true;
				break;
			}
			last.push_back(now);
			ef[p[i].S]=1;
			et[p[i].S]=now++;
		}
		else{
			while(!last.empty()&&pe[last.back()]<=1) last.pop_back();
			if(!last.empty()){
				ef[p[i].S]=pe[last.back()]--;
				et[p[i].S]=last.back();
			}
			else{
				wrong=true;
				break;
			}
		}
	}
	if(wrong) puts("-1");
	else{
		for(int i=0;i<m;i++){
			printf("%d %d\n",ef[i],et[i]);
		}
	}
	return 0;
}