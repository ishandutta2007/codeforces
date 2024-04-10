#include<stdio.h>
#include<vector>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005;
int n,T,a[N];
vector<int> vec[N];
int main(){ 
	scanf("%d",&T);it i,j;
	while(T--){
		scanf("%d",&n);it cn=1;
		for(i=1;i<=n;++i) scanf("%d",&a[i]),cn+=(a[i]<a[i-1]),vec[cn].push_back(a[i]);
	//	for(i=1;i<=cn;puts(""),++i) for(const int &j : vec[i]) printf("%d ",j);
		/*it lst=a[n],fl1=1;
		for(i=cn-1;i;--i){
			it flag=1;
			for(j=vec[i].size()-1;~j;--j)
				if(vec[i][j]<lst){flag=0;break;}
			if(flag){fl1=0;break;}
		}
		lst=a[1];it fl2=1;
		for(i=2;i<=cn;++i){
			it flag=1;
			for(j=0;j<vec[i].size();++j)
				if(vec[i][j]>lst){flag=0;break;}
			if(flag){fl2=0;break;}
		}
		fl1||fl2?puts("YES"):puts("NO");
		for(i=1;i<=cn;++i) vec[i].clear();*/
		a[1]<a[n]?puts("YES"):puts("NO");
	}
	return 0;
}