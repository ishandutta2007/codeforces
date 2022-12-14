#include <bits/stdc++.h>
int A[100]={}, B[100]={};
int main()
{
	int N, idx=0, jogun=1, gasu=0, type=1, i, idxB=0, M;
	scanf("%d", &N);
	M=N;
	if(N%2==0)
	{
		N++;
		gasu+=2;
		B[0]=0;
		idxB++;
		while(N!=0)
		{
			A[idx]=N%2;
			N=N/2;
			if(A[idx]==0)
			jogun=0;
			idx++;
		}
		N=M+1;
		if(jogun==0)
		{
			idx-=2;
			while(idx!=0)
			{
				if(type!=A[idx])
				{
					gasu+=2;
					B[idxB]=idx+1;
					idxB++;
					type=A[idx];
				}
				idx--;
			}
		}
		printf("%d\n", gasu);
		for(i=0;i<idxB;i++)
		{
			printf("%d ", B[i]);
		}
	}
	N=M;
	if(N%2!=0)
	{
		while(N!=0)
		{
			A[idx]=N%2;
			N=N/2;
			if(A[idx]==0)
			jogun=0;
			idx++;
		}
		N=M;
		if(jogun!=0)
		{
			printf("0");
		}
		else
		{
			idx-=2;
			while(idx!=0)
			{
				if(type!=A[idx])
				{
					gasu+=2;
					B[idxB]=idx+1;
					idxB++;
					type=A[idx];
				}
				idx--;
			}
			printf("%d\n", gasu);
			for(i=0;i<idxB;i++)
			printf("%d ", B[i]);
		}
	}
}