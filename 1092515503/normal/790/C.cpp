/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,f[110][110][110][3];
char s[110];
vector<int>V,K,O;
void chmn(int&x,int y){if(x>y)x=y;}
int main(){
	scanf("%d%s",&n,s);
	for(int i=0;i<n;i++){
		if(s[i]=='V')V.push_back(i);
		else if(s[i]=='K')K.push_back(i);
		else O.push_back(i);
	}
	if(V.empty()||K.empty()){puts("0");return 0;}
	memset(f,0x3f,sizeof(f));
	f[1][0][0][0]=0;
	f[0][1][0][1]=0;
	if(!O.empty())f[0][0][1][2]=0;
	for(int i=0;i<=V.size();i++)for(int j=0;j<=K.size();j++)for(int k=0;k<=O.size();k++)
		for(int t=0;t<3;t++)if(f[i][j][k][t]!=0x3f3f3f3f){
			int val=f[i][j][k][t];
			// printf("%d,%d,%d,%d:%d\n",i,j,k,t,val);
			if(i!=V.size()){
				int lav=val;
				for(int p=0;p<i;p++)lav+=(V[p]>V[i]);
				for(int p=0;p<j;p++)lav+=(K[p]>V[i]);
				for(int p=0;p<k;p++)lav+=(O[p]>V[i]);
				chmn(f[i+1][j][k][0],lav);
			}
			if(j!=K.size()&&t){
				int lav=val;
				for(int p=0;p<i;p++)lav+=(V[p]>K[j]);
				for(int p=0;p<j;p++)lav+=(K[p]>K[j]);
				for(int p=0;p<k;p++)lav+=(O[p]>K[j]);
				chmn(f[i][j+1][k][1],lav);
			}
			if(k!=O.size()){
				int lav=val;
				for(int p=0;p<i;p++)lav+=(V[p]>O[k]);
				for(int p=0;p<j;p++)lav+=(K[p]>O[k]);
				for(int p=0;p<k;p++)lav+=(O[p]>O[k]);
				chmn(f[i][j][k+1][2],lav);
			}
		}
	printf("%d\n",min({f[V.size()][K.size()][O.size()][0],f[V.size()][K.size()][O.size()][1],f[V.size()][K.size()][O.size()][2]}));
	return 0;
}