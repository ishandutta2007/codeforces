#include<bits/stdc++.h>
using namespace std;
string a; int N;
string b; int M;
int prevx[101010];
int back[101010];
int main()
{
	cin >> a >> b;
	N = a.size();
	M = b.size();
	a = "$"+a+"$";
	b = "$"+b+"$";
	prevx[0]=0;
	prevx[M+1]=121212;
	for(int i=1; i<=M; i++)
	{
		prevx[i]=121212;
		for(int k=prevx[i-1]+1; k<=N; k++)
		{
			if(b[i] == a[k])
			{
				prevx[i] = k;
				break;
			}
		}
	}
	back[M+1] = N+1;
	back[0] = -999999;
	for(int i=M; i>=1; i--)
	{
		back[i]=-121212;
		for(int k=back[i+1]-1; k>=1; k--)
		{
			if(b[i] == a[k])
			{
				back[i] = k;
				break;
			}
		}
	}
	int maxv=0;
	int maxi1=0;
	int maxi2=M+1;
	int pivot = M+1;
	for(int i=0; i<=M && prevx[i]<101010; i++)
	{
		while(prevx[i]<back[pivot] && i<pivot)
			pivot--;
		pivot++;
		int v = i+(M+1)-pivot;
		if(maxv<v)
		{
			maxv = v;
			maxi1 = i;
			maxi2 = pivot;
		}
	}
	if(maxv==0) putchar('-');
	for(int i=1; i<=maxi1;i++) printf("%c",b[i]);
	for(int i=maxi2; i<=M; i++) printf("%c",b[i]);
	puts("");
	return 0;
}