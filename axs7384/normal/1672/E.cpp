#include<bits/stdc++.h>
using namespace std;
inline int ask(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	int p;
	scanf("%d",&p);
	return p;
}
int main()
{
	int n;
	scanf("%d",&n);
	int l=n*2-1,r=n*2001;
	while (l<=r)
	{
		int mid=(l+r)/2;
		int p=ask(mid);
		if (p==1)
			r=mid-1;
		else
			l=mid+1;
	}
	int x=l,ans=l;
	for (int i=2;i<=n;++i)
	{
		// cout<<"..."<<i<<' '<<(x-1)/i<<endl;
		int k=ask(x/i);
		if (k!=0)
			ans=min(ans,k*(x/i));
	}
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}




// i
// (x-1)/i+1
// (x-(i-1)+(i-1))/i  shang
// 3 3 3 11



// 18

// fen 3 


// 1 1 2 2

// 9

// 8
// x/i *i