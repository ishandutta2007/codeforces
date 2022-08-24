#include<stdio.h>
int m,i,w[12],D[12][12],t,c,C,j,k;
__int64 Mod=1000000007,P[12],S[12],Res;
int chk(int a){
	if(a==4||a==7)return 1;
	return 0;}
void DFS(int a,int b,__int64 T){
	int i;
	if(a==6){
		for(i=b+1;i<=c;i++){
			Res+=T*P[i];
			Res%=Mod;}
		Res%=Mod;
		return;
	}
	for(i=0;i<c;i++){
		if(b+i>=c)break;
		P[i]--;
		DFS(a+1,b+i,((P[i]+(__int64)1)*T)%Mod);
		P[i]++;
	}
}
int main()
{
	scanf("%d",&m);
	t=m;
	while(t){w[c++]=t%10,t/=10;}
	for(i=0;i<w[c-1];i++)D[c-1][chk(i)]++;
	if(chk(w[c-1]))C++;
	for(i=c-2;i>=0;i--){
		for(j=0;j<w[i];j++)D[i][C+chk(j)]++;
		for(j=0;j<=c-1-i;j++){
			for(k=0;k<10;k++){
				D[i][j+chk(k)]+=D[i+1][j];
			}
		}
		if(chk(w[i]))C++;
	}
	D[0][0]--,D[0][C]++;
	for(i=0;i<=c;i++){
		P[i]=D[0][i];
		if(i==0)S[i]=P[i];
		else S[i]=S[i-1]+P[i];}
	DFS(0,0,1);
	printf("%I64d\n",Res);
}