#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define F first
#define S second

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
II A[3];
int main()
{
	for(int i=0;i<3;i++)
		si(A[i].F),si(A[i].S);
	sort(A,A+3);
	if(A[0].F==A[1].F && A[1].F==A[2].F)
	{
		dout(1);
		return 0;
	}
	if(A[0].S==A[1].S && A[1].S==A[2].S)
	{
		dout(1);
		return 0;
	}
	if(A[0].S==A[1].S)
	{
		if(A[2].F >= A[1].F || A[2].F <= A[0].F)dout(2);
		else dout(3);
		return 0;
	}
	if(A[1].S==A[2].S)
	{

		if(A[0].F <= A[1].F || A[0].F >= A[2].F)dout(2);
		else dout(3);
		return 0;
	}
	if(A[0].S==A[2].S)
	{
		if(A[1].F <= A[0].F || A[1].F >= A[2].F)dout(2);
		else dout(3);
		return 0;
	}
	for(int i=0;i<3;i++)swap(A[i].F,A[i].S);
	sort(A,A+3);
	if(A[0].S==A[1].S)
	{
		if(A[2].F >= A[1].F || A[2].F <= A[0].F)dout(2);
		else dout(3);
		return 0;
	}
	if(A[1].S==A[2].S)
	{

		if(A[0].F <= A[1].F || A[0].F >= A[2].F)dout(2);
		else dout(3);
		return 0;
	}
	if(A[0].S==A[2].S)
	{
		if(A[1].F <= A[0].F || A[1].F >= A[2].F)dout(2);
		else dout(3);
		return 0;
	}

	dout(3);
	return 0;
}