#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ll long long
using namespace std;

ll tag_A[350],sum_B[350],tag_B[350],A[100000],B[100000];

int main()
{jizz
	ll i,j,n,q,sqn,k,ql,qr,l,r,x,id,re;
	cin >> n >> q;
	sqn=sqrt(n);
	for(i=0;i<n;i++)
		A[i]=i+1; 
	while(q--)
	{
		cin >> k >> ql >> qr,ql--,qr--;
		if(k==1)
		{
			cin >> x;
			for(i=ql;i<=qr;)
			{
				id=i/sqn,l=id*sqn,r=min(n,l+sqn);
				if(i==l && qr>=r-1)
				{
					if(tag_A[id])
						sum_B[id]+=abs(tag_A[id]-x)*(r-l),tag_B[id]+=abs(tag_A[id]-x);
					else
						for(j=l;j<r;j++) B[j]+=abs(A[j]-x),sum_B[id]+=abs(A[j]-x);
					tag_A[id]=x,i=r;
				}
				else 
				{
					if(tag_A[id])
					{
						for(j=l;j<r;j++) A[j]=tag_A[id];
						tag_A[id]=0;
					}
					sum_B[id]+=abs(A[i]-x),B[i]+=abs(A[i]-x),A[i]=x;
					i++;
				}
			}
		}
		else
		{
			re=0;
			for(i=ql;i<=qr;)
			{
				id=i/sqn,l=id*sqn,r=min(n,l+sqn);
				if(i==l && qr>=r-1)
					re+=sum_B[id],i=r;
				else
					re+=B[i]+tag_B[id],i++;
			} 
			cout << re << "\n";
		}
	}
}