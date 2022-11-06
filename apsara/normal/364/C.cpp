#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=1701000;
int N;
int a[V],t;
int ct[120];
int pn;
int pr[]={2,3,5,7,11,13};
void dfs(int x,int last)
{
	if(x>N)return;
	if(x!=1)a[t++]=x;
	for(int i=0;i<pn;i++)
	if(last<=pr[i])dfs(pr[i]*x,pr[i]);
}
bool cmp(int x,int y)
{
    int ca=0;
    int cb=0;
    for(int i=0;i<pn;i++)
    {if(x%pr[i]==0)ca++;
    if(y%pr[i]==0)cb++;}
    if(ca!=cb)return ca>cb;
    else return x<y;
}
int K;
int main()
{
    while(~scanf("%d",&K))
	//for(int K=10;K<=5000;K++)
    {
        t=0;N=2*K*K;
        if(K<=64)pn=2;
        else if(K<=400)pn=3;
        else if(K<=2000)pn=4;
        else pn=5;
        memset(ct,0,sizeof(ct));
        dfs(1,2);
        sort(a,a+t,cmp);
        for(int j=0;j<K;j++)
        for(int i=0;i<pn;i++)
        if(a[j]%pr[i]==0)ct[i]++;
        //printf("%d\n",t);
        //for(int i=0;i<pn;i++)printf("%d ",ct[i]);puts("");
		//for(int i=0;i<pn;i++)if(ct[i]*2<K){printf("%d\n",K);break;}
		//if(t<K){printf("%d %d\n",K,t);break;}
        for(int i=0;i<K;i++)printf("%d ",a[i]);puts("");
        //if(K%100==0)printf("DD %d\n",K);
    }
	return 0;
}