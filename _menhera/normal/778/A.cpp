#include<bits/stdc++.h>
using namespace std;
char A[201010];
int N;
char B[201010];
int M;
int P[202020];
bool vo[202020];
char ns[202020];
int le = 0;
bool issubstr(char *A, int N, char *B, int M)
{
	if(N<M) return false;
	int i=0, j=0;
	for(int i=0; i<N; ++i)
	{
		if(A[i]==B[j]) ++j;
		if(j==M) return true;
	}
	return false;
}
bool can(int cnt)
{
	memset(vo, false, sizeof(vo));
	for(int i=0; i<cnt; ++i) vo[P[i]]=true;
	le = 0;
	for(int i=0; i<N; ++i)
	{
		if(!vo[i])
			ns[le++] = A[i];
	}
	ns[le] = 0;
	return issubstr(ns, le, B, M);
}
int main()
{
	scanf("%s%s",A,B);
	N = strlen(A);
	M = strlen(B);
	for(int i=0; i<N; ++i)
	{
		scanf("%d",P+i);
		P[i]--;
	}
	int lo = 0; //can 
	int hi = N; //cant
	while(lo+1!= hi)
	{
		int mi = (lo+hi)/2;
		if(can(mi)) lo = mi;
		else hi = mi;
	}
	printf("%d\n",lo);
	return 0;
}