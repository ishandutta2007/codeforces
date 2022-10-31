#include<cstdio>
#include<cmath>
#define N 110
#define M 1000000
using namespace std;
double nc[N],p[N];
int x[N];
int main(){
	int n;
	double ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",&p[i]);
		p[i]=0.01*(100-p[i]);
		nc[i]=1;
	}
	for(int i=0;i<M;i++){
		double tmp=1,bst=1,tr;
		int ch=0;
		for(int j=0;j<n;j++){
			tmp*=(1-nc[j]);
			if(nc[j]>1-1e-8){
				ch=j;
				break;
			}
			tr = (1-nc[j]*p[j])/(1-nc[j]);
			if(tr>bst) bst=tr,ch=j;
		}
		nc[ch]*=p[ch];
		ans+=1-tmp;
	}
	printf("%.12f\n",ans);
	return 0;
}