#include<stdio.h>
#include<algorithm>
using namespace std;
__int64 a,b,w[10000],s,K=10000,c1,c2,c,i;
void DFS(){
	if(c1==c2&&s!=0) w[c++]=s;
	if(s>K){
		return;}
	s=s*10+4,c1++;
	DFS();
	s=(s-4)/10,c1--;
	s=s*10+7,c2++;
	DFS();
	s=(s-7)/10,c2--;
}
int main(){
	K*=1000000;
	scanf("%I64d",&a);
	DFS();
	sort(w,w+c);
	for(i=0;i<c;i++) if(a<=w[i])break;
	printf("%I64d\n",w[i]);
}