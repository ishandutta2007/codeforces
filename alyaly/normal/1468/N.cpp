#include<bits/stdc++.h>
using namespace std;
int T;
int A[6],C[6];
void p1(void)
{
	puts("NO");
	return;
}
void p2(void)
{
	puts("YES");
	return;
}
void solve(void)
{
	for(int i=1;i<=3;i++)cin>>C[i];
	for(int i=1;i<=5;i++)cin>>A[i];
	for(int i=1;i<=3;i++)C[i]-=A[i];
	for(int i=1;i<=3;i++)if(C[i]<0)return p1();
	A[4]-=C[1];A[5]-=C[2];
	A[4]=max(A[4],0);A[5]=max(A[5],0);
	if(A[4]+A[5]>C[3])return p1();
	return p2();
}
int main()
{
	cin>>T;
	while(T--)solve();
	return 0;
}
/*
1
2 2 3 
1 2 3 0 1 
*/