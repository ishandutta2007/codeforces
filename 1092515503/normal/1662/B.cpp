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
int n[3],m,p,res;
char s[3][1010];
int num[3][26];
vector<char>v[3];
int main(){
	for(int i=0;i<3;i++){
		scanf("%s",s[i]),n[i]=strlen(s[i]);
		for(int j=0;j<n[i];j++)num[i][s[i][j]-'A']++;
	}
	for(int i=0;i<26;i++)while(true){
		int j,k;
		if(num[0][i]>=num[2][i]&&num[1][i]>=num[2][i])j=0,k=1;
		if(num[0][i]>=num[1][i]&&num[2][i]>=num[1][i])j=0,k=2;
		if(num[1][i]>=num[0][i]&&num[2][i]>=num[0][i])j=1,k=2;
		if(!num[j][i]||!num[k][i])break;
		num[j][i]--,num[k][i]--,m++;
	}
	// printf("GUGU:%d\n",m);
	m=min({m,n[0],n[1],n[2]});
	p=(n[0]+n[1]+n[2]-m+1)/2;
	res=max({n[0],n[1],n[2],p});
	printf("%d\n",res);
	memset(num,0,sizeof(num));
	for(int i=0;i<3;i++)for(int j=0;j<n[i];j++)num[i][s[i][j]-'A']++;
	for(int i=0;i<26;i++)while(m){
		int j,k;
		if(num[0][i]>=num[2][i]&&num[1][i]>=num[2][i])j=0,k=1;
		if(num[0][i]>=num[1][i]&&num[2][i]>=num[1][i])j=0,k=2;
		if(num[1][i]>=num[0][i]&&num[2][i]>=num[0][i])j=1,k=2;
		if(!num[j][i]||!num[k][i])break;
		num[j][i]--,num[k][i]--,m--;
		v[3^j^k].push_back('A'+i);
	}
	for(int i=0;i<26;i++)for(int j=0;j<3;j++)
		while(num[j][i]&&!v[j].empty())printf("%c%c\n",'A'+i,v[j].back()),v[j].pop_back(),num[j][i]--;
	for(int i=0;i<26;i++)for(int j=0;j<3;j++)while(num[j][i])v[j].push_back('A'+i),num[j][i]--;
	while(true){
		int j,k;
		if(v[0].size()>=v[2].size()&&v[1].size()>=v[2].size())j=0,k=1;
		if(v[0].size()>=v[1].size()&&v[2].size()>=v[1].size())j=0,k=2;
		if(v[1].size()>=v[0].size()&&v[2].size()>=v[0].size())j=1,k=2;
		if(v[j].empty()||v[k].empty())break;
		printf("%c%c\n",v[j].back(),v[k].back());
		v[j].pop_back(),v[k].pop_back();
	}
	for(int i=0;i<3;i++)while(!v[i].empty())printf("%c%c\n",v[i].back(),v[i].back()),v[i].pop_back();
	return 0;
}