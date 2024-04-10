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
int n,m,res=-1;
char g[300100];
int col[300100][2][4],row[300100][2][4];
int HS(char c){
	if(c=='A')return 0;
	if(c=='C')return 1;
	if(c=='G')return 2;
	if(c=='T')return 3;
}
int SH(int i){
	if(i==0)return 'A';
	if(i==1)return 'C';
	if(i==2)return 'G';
	if(i==3)return 'T';
}
char t[10];
char r[2][300100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",g+i*m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)col[j][i&1][HS(g[i*m+j])]++,row[i][j&1][HS(g[i*m+j])]++;
	t[0]='A',t[1]='C',t[2]='G',t[3]='T';
	do{
		int tot=0;
		for(int i=0;i<m;i++)
			if(i&1)tot+=max(col[i][0][HS(t[0])]+col[i][1][HS(t[2])],col[i][1][HS(t[0])]+col[i][0][HS(t[2])]);
			else tot+=max(col[i][0][HS(t[1])]+col[i][1][HS(t[3])],col[i][1][HS(t[1])]+col[i][0][HS(t[3])]);
		res=max(res,tot);
	}while(next_permutation(t,t+4));
	t[0]='A',t[1]='C',t[2]='G',t[3]='T';
	do{
		int tot=0;
		for(int i=0;i<n;i++)
			if(i&1)tot+=max(row[i][0][HS(t[0])]+row[i][1][HS(t[2])],row[i][1][HS(t[0])]+row[i][0][HS(t[2])]);
			else tot+=max(row[i][0][HS(t[1])]+row[i][1][HS(t[3])],row[i][1][HS(t[1])]+row[i][0][HS(t[3])]);
		res=max(res,tot);
	}while(next_permutation(t,t+4));
	t[0]='A',t[1]='C',t[2]='G',t[3]='T';
	do{
		int tot=0;
		for(int i=0;i<m;i++)
			if(i&1)tot+=max(col[i][0][HS(t[0])]+col[i][1][HS(t[2])],col[i][1][HS(t[0])]+col[i][0][HS(t[2])]);
			else tot+=max(col[i][0][HS(t[1])]+col[i][1][HS(t[3])],col[i][1][HS(t[1])]+col[i][0][HS(t[3])]);
		if(tot!=res)continue;
		for(int i=0;i<m;i++)
			if(i&1){
				if(col[i][0][HS(t[0])]+col[i][1][HS(t[2])]>col[i][1][HS(t[0])]+col[i][0][HS(t[2])])
					r[0][i]=t[0],r[1][i]=t[2];
				else r[0][i]=t[2],r[1][i]=t[0];
			}else{
				if(col[i][0][HS(t[1])]+col[i][1][HS(t[3])]>col[i][1][HS(t[1])]+col[i][0][HS(t[3])])
					r[0][i]=t[1],r[1][i]=t[3];
				else r[0][i]=t[3],r[1][i]=t[1];
			}
		for(int i=0;i<n;i++,putchar('\n'))for(int j=0;j<m;j++)putchar(r[i&1][j]);
		return 0;
	}while(next_permutation(t,t+4));
	t[0]='A',t[1]='C',t[2]='G',t[3]='T';
	do{
		int tot=0;
		for(int i=0;i<n;i++)
			if(i&1)tot+=max(row[i][0][HS(t[0])]+row[i][1][HS(t[2])],row[i][1][HS(t[0])]+row[i][0][HS(t[2])]);
			else tot+=max(row[i][0][HS(t[1])]+row[i][1][HS(t[3])],row[i][1][HS(t[1])]+row[i][0][HS(t[3])]);
		if(tot!=res)continue;
		for(int i=0;i<n;i++)
			if(i&1){
				if(row[i][0][HS(t[0])]+row[i][1][HS(t[2])]>row[i][1][HS(t[0])]+row[i][0][HS(t[2])])
					r[0][i]=t[0],r[1][i]=t[2];
				else r[0][i]=t[2],r[1][i]=t[0];
			}else{
				if(row[i][0][HS(t[1])]+row[i][1][HS(t[3])]>row[i][1][HS(t[1])]+row[i][0][HS(t[3])])
					r[0][i]=t[1],r[1][i]=t[3];
				else r[0][i]=t[3],r[1][i]=t[1];
			}
		for(int i=0;i<n;i++,putchar('\n'))for(int j=0;j<m;j++)putchar(r[j&1][i]);
		return 0;
	}while(next_permutation(t,t+4));
	return 0;
}